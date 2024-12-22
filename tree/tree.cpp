#include "tree.h"

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
bool isSymmetric(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }

    std::vector<TreeNode*> queue;
    queue.push_back(root);
    while(queue.size() > 0) {
        size_t queue_len = queue.size();
        for(size_t i = 0; i < queue_len; ++i) {
            if(queue[i] == nullptr && queue[queue_len - i - 1] == nullptr) {
                continue;
            }

            if(queue[i] == nullptr || queue[queue_len - i - 1] == nullptr) {
                return false;
            }

            if(queue[i]->getValue() != queue[queue_len - i - 1]->getValue()) {
                return false;
            }

            queue.push_back(queue[i]->getLeftNode());
            queue.push_back(queue[i]->getRightNode());
        }

        queue.erase(queue.begin(), queue.begin() + queue_len);
    }
    return true;
}

//--------------------------------- Task 2 ---------------------------------
std::vector<TreeNode*> deptSesrch(TreeNode* root, std::vector<TreeNode*> res) {
    if(root == nullptr) {
        return res;
    }

    res = deptSesrch(root->getLeftNode(), res);
    res.push_back(root);
    res = deptSesrch(root->getRightNode(), res);

    return res;
}

bool isSymmetricDFS(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }

    std::vector<TreeNode*> DFSres;
    DFSres = deptSesrch(root, DFSres);
    size_t DFSres_size = DFSres.size();

    for(size_t i = 0, j = DFSres_size - 1; i < DFSres_size / 2; ++i, --j) {
        if(DFSres[i]->getValue() != DFSres[j]->getValue()) {
            return false;
        }
    }
    return true;
}

//--------------------------------- Task 3 ---------------------------------
size_t minDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    size_t left_node_depth = minDepth(root->getLeftNode());
    size_t right_node_depth = minDepth(root->getRightNode());
    return 1 + std::min(left_node_depth, right_node_depth);
}

//--------------------------------- Task 4 ---------------------------------
int maxMinMultiplication(TreeNode* root) {
    TreeNode* min_node = root;
    TreeNode* max_node = root;

    while(min_node->getLeftNode() != nullptr) {
        min_node = min_node->getLeftNode();
    }

    while(max_node->getRightNode() != nullptr) {
        max_node = max_node->getRightNode();
    }

    return min_node->getValue() * max_node->getValue();
}

//--------------------------------- Task 5 ---------------------------------
bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr) {
        return false;
    }

    if(root1->getValue() != root2->getValue()) {
        return false;
    }
    return isSameTree(root1->getLeftNode(), root2->getLeftNode()) 
        && isSameTree(root1->getRightNode(), root2->getRightNode());
}
