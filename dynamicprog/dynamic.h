#ifndef DYNAMIC_H_
#define DYNAMIC_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <gtest/gtest.h>

class TreeNode {
private:
    int value_;
    TreeNode* left_;
    TreeNode* right_;

public:
    TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr): 
        value_(value), left_(left), right_(right) {}

    void addLeftNode(TreeNode* left) {
        left_ = left;
    }

    void addRightNode(TreeNode* right) {
        right_ = right;
    }

    TreeNode* getRightNode() const {
        return right_;
    }

    TreeNode* getLeftNode() const {
        return left_;
    }

    int getValue() const {
        return value_;
    }
};

class Tree {
private:
    TreeNode* root_;
public:
    Tree(std::vector<int> array): 
        root_(array.size() == 0 ? nullptr : new TreeNode(buildTree(array, 0))) {}

    TreeNode buildTree(std::vector<int> array, size_t array_index);

    TreeNode* getRoot() const {
        return root_;
    }
};

size_t countSequences(size_t n);
size_t findLIS(std::vector<int> nums, size_t n);
std::vector<std::vector<size_t>> pascalTriangle(size_t n);
int maxPathSum(TreeNode* root);
int maxProfit(std::vector<int> prices, size_t n);

#endif // #define DYNAMIC_H_