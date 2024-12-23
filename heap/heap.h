#ifndef TREE_x_HEAP_H_
#define TREE_x_HEAP_H_

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <gtest/gtest.h>

//--------------------------------- Tree ---------------------------------
class TreeNode {
private:
    int value_;
    TreeNode* left_;
    TreeNode* right_;

    size_t balance_factor_ = 0;

public:
    TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr): 
        value_(value), left_(left), right_(right) {}

    void addLeftNode(TreeNode* left) {
        left_ = left;
    }

    void addRightNode(TreeNode* right) {
        right_ = right;
    }

    void setBalanceFactor(size_t balance_factor) {
        balance_factor_ = balance_factor;
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

    size_t getBalanceFactor() const {
        return balance_factor_;
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


//--------------------------------- Heap ---------------------------------
class MinHeap {
private:
    std::vector<int> heap_{};
    size_t size_ = 0;

public:
    std::vector<int> getHeap() const {
        return heap_;
    }

    size_t getSize() const {
        return size_;
    }

    void print() {
        for(size_t i = 0; i < size_; ++i) {
            std::cout << heap_[i] << " ";
        }
        std::cout << std::endl;
    }

    void pushNode(int value) {
        heap_.push_back(value);
        size_t index = size_++;

        while(index > 0 && heap_[parentNode(index)] > heap_[index]) {
            int tmp = heap_[parentNode(index)];
            heap_[parentNode(index)] = heap_[index];
            heap_[index] = tmp;

            index = parentNode(index);
        }
    }

    int popNode() {
        int value = heap_[size_--];
        heap_.pop_back();
        return value;
    }

private:
    size_t parentNode(size_t index) {
        if(index % 2 == 1) {
            return (index - 1) / 2;
        }
        return (index - 2) / 2;
    }
};

bool isMaxHeap(std::vector<int> array);
std::vector<int> mergeKSortedArrays(std::vector<std::vector<int>> array);
int inorderMinIterative(TreeNode* root, size_t k);
size_t calculateHeightsAndBalance(TreeNode* root);
void mirrorTree(TreeNode* root);

#endif // #define TREE_x_HEAP_H_