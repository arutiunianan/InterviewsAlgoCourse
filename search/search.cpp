#include "search.h"

//--------------------------------- Task 1 ---------------------------------
bool isSubsequenceQueue(std::vector<int>& a, std::vector<int>& b) {
    std::queue<int> q;
    for(int el: a) {
        q.push(el);
    }

    for(int el: b) {
        if(q.front() == el) {
            q.pop();
        }
    }

    return q.empty();
}

//--------------------------------- Task 2 ---------------------------------
bool isSubsequencePointers(std::vector<int>& a, int n, 
                           std::vector<int>& b, int m) {
    int i = 0;
    int j = 0;

    while(i < n && j < m) {
        if(a[i] == b[j]) {
            ++i;
        }
        ++j;
    }

    return i == n;
}

//--------------------------------- Task 3 ---------------------------------
bool isPalindrome(std::string& s) {
    std::stack<char> stack;
    for(char sym: s) {
        stack.push(sym);
    }

    unsigned long i = 0;
    while(i < s.size()) {
        if(s[i] != stack.top()) {
            return false;
        }
        stack.pop();
        ++i;
    }
    return true;
}

//--------------------------------- Task 4 ---------------------------------
bool isPalindrome(std::string& s, int n) {
    int left = 0;
    int right = n - 1;
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

//--------------------------------- Task 5 ---------------------------------
int binarySearchSqrt(int target) {
    int left = 0;
    int right = target;
    while(left <= right) {
        int middle = left + (right - left) / 2;
        if(middle * middle > target) {
            right = middle - 1;
            continue;
        }
        if(middle * middle < target) {
            left = middle + 1;
            continue;
        }
        return middle;
    }
    return right;
}

//--------------------------------- Task 6 ---------------------------------
int copyTime(int n, int x, int y) {
    int max, min;
    if(x > y) {
        max = x;
        min = y;
    }
    else {
        max = y;
        min = x;
    }

    int left = 0;
    int right = (n - 1) * max;
    while(left + 1 < right) {
        int middle = left + (right - left) / 2;
        if(middle/x + middle/y < n -  1) {
            left = middle;
        }
        else {
            right = middle;
        }
    }
    return right + min;
}

//----------------------------------- HW -----------------------------------
std::string deleteDuplicates(std::string s) {
    unsigned long i = 0;
    while(i < s.size() - 1 && s.size() != 0) {
        if(s[i] == s[i + 1]) {
            s.erase(i, 2);
            if(i != 0) {
                --i;
            }
        }
        else {
            ++i;
        }
    }
    return s;
}

//--------------------------------------------------------------------------