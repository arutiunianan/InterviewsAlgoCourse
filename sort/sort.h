#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <gtest/gtest.h>

void sortShell(std::vector<int>& array, int n);
int feedAnimals(std::vector<int>& animals, int n,
                std::vector<int>& food,   int m);
std::string extraLetter(std::string& a, std::string& b);
std::pair<int, int> twoSum(std::vector<int> data, int n, int target);
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs, int n);

#endif // #define SORT_H_