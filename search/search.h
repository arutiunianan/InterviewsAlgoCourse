#ifndef SEARCH_H_
#define SEARCH_H_

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <queue>
#include <string>
#include <stack>

bool isSubsequenceQueue(std::vector<int>& a, std::vector<int>& b);
bool isSubsequencePointers(std::vector<int>& a, int n, 
                           std::vector<int>& b, int m);
bool isPalindrome(std::string& s);
bool isPalindrome(std::string& s, int n);
int binarySearchSqrt(int target);
int copyTime(int n, int x, int y);
std::string deleteDuplicates(std::string s);

#endif // #define SEARCH_H_