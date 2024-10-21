#include "array.h"

//--------------------------------- Task 1 ---------------------------------
void reverseArray(std::vector<int>& array, int n) {
    int left = 0;
    int right = n - 1;

    while(left < right) {
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;

        left++;
        right--;
    }
}

//--------------------------------- Task 2 ---------------------------------
void reverseArray(std::vector<int>& array, int left, int right) {
    while(left < right) {
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;

        left++;
        right--;
    }
}

void reverseArrayPart(std::vector<int>& array, int n, int k) {
    if(k >= n) {
        k = k % n;
    }
    reverseArray(array, 0, n - 1);
    reverseArray(array, 0, k - 1);
    reverseArray(array, k, n - 1);
}

//--------------------------------- Task 3 ---------------------------------
std::vector<int> mergeSortedArrays(std::vector<int>& arr1, int n, 
                                   std::vector<int>& arr2, int m) {
    std::vector<int> merged_array;

    int i = 0;
    int j = 0;
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            merged_array.push_back(arr1[i]);
            i++;
        }
        else {
            merged_array.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n) {
        merged_array.push_back(arr1[i]);
        i++;
    }
    while(j < m) {
        merged_array.push_back(arr2[j]);
        j++;
    }

    return merged_array;
}

//--------------------------------- Task 4 ---------------------------------
void merge(std::vector<int>& arr1, int n, 
           std::vector<int>& arr2, int m) {
    int pointer1 = n + m - 1;
    int pointer2 = n - 1;
    int pointer3 = m - 1;
    
    while(pointer2 != -1 && pointer3 != -1) {
        if(arr1[pointer2] >= arr2[pointer3]) {
            arr1[pointer1] = arr1[pointer2];
            pointer2--;
        }
        else {
            arr1[pointer1] = arr2[pointer3];
            pointer3--;
        }
        pointer1--;
    }

    while(pointer3 != -1) {
        arr1[pointer1] = arr2[pointer3];
        pointer3--;
        pointer1--;
    }
}


//--------------------------------- Task 5 ---------------------------------
void evenFirst(std::vector<int>& array, int n) {
    int pointer = 0;
    for(int i = 0; i < n; i++) {
        if(array[i] % 2 == 0) {
            int tmp = array[pointer];
            array[pointer] = array[i];
            array[i] = tmp;
            pointer++;
        }
    }
}


//----------------------------------- HW -----------------------------------
void zerosAtTheEnd(std::vector<int>& array, int n) {
    int pointer = 0;
    for(int i = 0; i < n; i++) {
        if(array[i] != 0) {
            array[pointer] = array[i];
            array[i] = 0;
            pointer++;
        }
    }
}

//--------------------------------------------------------------------------