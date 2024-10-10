#include <stdlib.h>
#include <stdio.h>

int* reverseArray(int* array, int n) {
    int left = 0;
    int right = n - 1;

    while(left < right) {
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;

        left++;
        right--;
    } 

    return array;
}

///////

int* reverseArray(int* array, int left, int right) {
    while(left < right) {
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;

        left++;
        right--;
    }
    return array;
}

int* solution(int* array, int n, int k) {
    reverseArray(array, 0, n - 1);
    reverseArray(array, 0, k - 1);
    reverseArray(array, k, n - 1);

    return array;
}

///////

int* merge_sorted_arrays(int* arr1, int* arr2, int n, int m) {
    int* merged_array = (int*)malloc(n+m);

    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            merged_array[k] = arr1[i];
            i++;
        }
        else {
            merged_array[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n) {
        merged_array[k] = arr1[i];
        i++;
        k++;
    }
    while(j < m) {
        merged_array[k] = arr2[j];
        j++;
        k++;
    }

    return merged_array;
}

//////

int* merge(int* arr1, int* arr2, int n, int m) {
    int pointer1 = n + m - 1;
    int pointer2 = n - 1;
    int pointer3 = m - 1;
    
    while(pointer2 != 0 && pointer3 != 0) {
        if(arr1[pointer2] > arr2[pointer3]) {
            arr1[pointer1] = arr1[pointer2];
            pointer2--;
        }
        else {
            arr1[pointer1] = arr2[pointer3];
            pointer3--;
        }
        pointer1--;
    }

    return arr1;
}

/////

int* evenFirst(int* array, int n) {
    int pointer = 0;
    for(int i = 0; i < n; i++) {
        if(array[i] % 2 == 0) {
            int tmp = array[pointer];
            array[pointer] = array[i];
            array[i] = tmp;
            pointer++;
        }
    }

    return array;
}