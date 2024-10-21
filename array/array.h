#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

void reverseArray(std::vector<int>& array, int n);
void reverseArrayPart(std::vector<int>& array, int n, int k);
std::vector<int> mergeSortedArrays(std::vector<int>& arr1, int n, 
                                   std::vector<int>& arr2, int m);
void merge(std::vector<int>& arr1, int n, 
           std::vector<int>& arr2, int m);
void evenFirst(std::vector<int>& array, int n);
void zerosAtTheEnd(std::vector<int>& array, int n);

#endif // #define ARRAY_H_