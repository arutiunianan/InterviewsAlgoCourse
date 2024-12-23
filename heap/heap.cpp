#include "heap.h"

TreeNode Tree::buildTree(std::vector<int> array, size_t array_index) {
    TreeNode root(array[array_index]);

    if(array_index * 2 + 1 < array.size()) {
        TreeNode* left_node = new TreeNode(buildTree(array, array_index * 2 + 1));
        root.addLeftNode(left_node);
    }
    if(array_index * 2 + 2 < array.size()) {
        TreeNode* right_node = new TreeNode(buildTree(array, array_index * 2 + 2));
        root.addRightNode(right_node);
    }
    
    return root;
}

//--------------------------------- Task 1 ---------------------------------
bool isMaxHeap(std::vector<int> array) {
    size_t array_size = array.size();
    if(array_size == 0 || array_size == 1) {
        return true;
    }

    for(size_t i = 0; i < array_size / 2; ++i) {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if(left < array_size && array[i] < array[left]) {
            return false;
        }
        if(right < array_size && array[i] < array[right]) {
            return false;
        }
    }
    return true;
}

//--------------------------------- Task 2 ---------------------------------
std::vector<int> mergeKSortedArrays(std::vector<std::vector<int>> array) {
    MinHeap minHeap{};
    for(size_t i = 0; i < array.size(); ++i) {
        for(size_t j = 0; j < array[i].size(); ++j) {
            minHeap.pushNode(array[i][j]);
        }
    }

    return minHeap.getHeap();
}

//--------------------------------- Task 3 ---------------------------------
int inorderMinIterative(TreeNode* root, size_t k) {
    std::list<TreeNode*> stack;
    size_t counter = 0;
    TreeNode* current = root;
    stack.push_back(current);

    while(stack.size() > 0) {
        while(current != nullptr) {
            stack.push_back(current);
            current = current->getLeftNode();
        }

        current = stack.back();
        stack.pop_back();
        ++counter;

        if(counter == k) {
            return current->getValue();
        }
        current = current->getRightNode();
    }
    return -1;
}

//--------------------------------- Task 4 ---------------------------------
size_t calculateHeightsAndBalance(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    size_t leftHeight = calculateHeightsAndBalance(root->getLeftNode());
    size_t rightHeight = calculateHeightsAndBalance(root->getRightNode());

    root->setBalanceFactor(leftHeight > rightHeight ? leftHeight - rightHeight 
                                                    : rightHeight - leftHeight);
    return 1 + std::max(leftHeight, rightHeight);
}

//--------------------------------- Task 5 ---------------------------------
void mirrorTree(TreeNode* root) {
    if(root == nullptr) {
        return;
    }

    TreeNode* tmp = root->getLeftNode();
    root->addLeftNode(root->getRightNode());
    root->addRightNode(tmp);

    mirrorTree(root->getLeftNode());
    mirrorTree(root->getRightNode());
}