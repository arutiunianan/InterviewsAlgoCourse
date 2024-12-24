#include "dynamic.h"

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
size_t countSequences(size_t n) {
    if(n == 0) {
        return n;
    }

    std::vector<size_t> dp{2, 4, 7};
    for(size_t i = 3; i < n; ++i) {
        dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
    }
    return dp[n - 1];
}

//--------------------------------- Task 2 ---------------------------------
size_t findLIS(std::vector<int> nums, size_t n) {
    if(n == 0 || n == 1) {
        return n;
    }

    std::vector<size_t> dp(n, 1);
    for(size_t i = 1; i < n; ++i) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }

    size_t max = 0;
    for(size_t i = 0; i < n; ++i) {
        if(dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}

//--------------------------------- Task 3 ---------------------------------
std::vector<std::vector<size_t>> pascalTriangle(size_t n) {
    std::vector<std::vector<size_t>> dp{n};
    for(size_t i = 0; i < n; ++i) {
        dp[i] = std::vector<size_t>(i + 1, 1);
    }

    for(size_t row = 2; row < n; ++row) {
        for(size_t col = 1; col < row; ++col) {
            dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
        }
    }
    return dp;
}

//--------------------------------- Task 4 ---------------------------------
int DFS(TreeNode* root, int& max) {
    if(root == nullptr) {
        return 0;
    }

    int leftWeight = DFS(root->getLeftNode(), max);
    int rightWeight = DFS(root->getRightNode(), max);

    int local_sum = root->getValue() + leftWeight + rightWeight;
    max = std::max(local_sum, max);

    return root->getValue() + std::max(leftWeight, rightWeight);
}

int maxPathSum(TreeNode* root) {
    int max = std::numeric_limits<int>::min();
    DFS(root, max);
    return max;
}

//--------------------------------- Task 5 ---------------------------------
int maxProfit(std::vector<int> prices, size_t n) {
    int profit = 0;
    int min_price = prices[0];

    for(size_t currentPriceIndex = 1; currentPriceIndex < n; ++currentPriceIndex) {
        profit = std::max(profit, prices[currentPriceIndex] - min_price);
        min_price = std::min(prices[currentPriceIndex], min_price);
    }

    return profit;
}