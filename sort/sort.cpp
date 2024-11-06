#include "sort.h"

//--------------------------------- Task 1 ---------------------------------
void sortShell(std::vector<int>& array, int n) {
    int gap =  n / 2;

    while(gap > 0) {
        int current_position = gap;

        while(current_position < n) {
            int i = 1;
            do {
                if(array[current_position - i*gap] > array[current_position - (i - 1)*gap]) {
                    int tmp = array[current_position - i*gap];
                    array[current_position - i*gap] = array[current_position - (i - 1)*gap];
                    array[current_position - (i - 1)*gap] = tmp;
                }
                
                ++i;
            } while(current_position - i*gap >= 0);
            
            ++current_position;
        }

        gap = gap / 2;
    }
}

//--------------------------------- Task 2 ---------------------------------

int feedAnimals(std::vector<int>& animals, int n,
                std::vector<int>& food,    int m) {
    if(n == 0 || m == 0) {
        return 0;
    }

    sortShell(animals, n);
    sortShell(food, m);

    int j = 0;
    int count = 0;
    for(int i = 0; i < n; ++i) {
        while(j < m && food[j] < animals[i]) {
            ++j;
        }

        if(j == m) {
            return count;
        }
        ++count;
        ++j;
    }
    return count;
}

//--------------------------------- Task 3 ---------------------------------

std::string extraLetter(std::string& a,
                        std::string& b) {
    int n = a.size();
    int m = b.size();
    if(n == m) {
        return "";
    }

    std::unordered_map<char, int> hashTable;
    for(int i = 0; i < n; ++i) {
        if(hashTable.find(a[i]) == hashTable.end()) {
            hashTable[a[i]] = 1;
        }
        else {
            ++hashTable[a[i]];
        }
    }

    for(int j = 0; j < m; ++j) {
        if(hashTable.find(b[j]) != hashTable.end() && hashTable[b[j]] != 0) {
            --hashTable[b[j]];
        }
        else {
            return std::string{b[j]};
        }
    }
}

//--------------------------------- Task 4 ---------------------------------

std::pair<int, int> twoSum(std::vector<int> data, int n, int target) {
    std::unordered_map<char, int> hashTable;
    for(int i = 0; i < n; ++i) {
        hashTable[data[i]] = i;
    }

    for(int i = 0; i < n; ++i) {
        int diff = target - data[i];
        if(hashTable.find(diff) != hashTable.end()) {
            return std::pair{data[i], diff};
        }
    }
    return {-1, -1};
}

//----------------------------------- HW -----------------------------------

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs, int n) {
    std::unordered_map<std::string, std::vector<std::string>> hashTable;
    for(int i = 0; i < n; ++i) {
        std::string key = strs[i];
        std::sort(key.begin(), key.end());
        hashTable[key].push_back(strs[i]);
    }

    std::vector<std::vector<std::string>> groups;
    for(auto& elem: hashTable) {
        groups.push_back(elem.second);
    }
    return groups;
}


//--------------------------------------------------------------------------