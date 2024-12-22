#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <vector>
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

std::vector<TreeNode*> deptSesrch(TreeNode* root, std::vector<TreeNode*> res);
bool isSymmetric(TreeNode* root);
bool isSymmetricDFS(TreeNode* root);
size_t minDepth(TreeNode* root);
int maxMinMultiplication(TreeNode* root);
bool isSameTree(TreeNode* root1, TreeNode* root2);

#endif // #define TREE_H_