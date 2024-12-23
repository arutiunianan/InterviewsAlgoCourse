#include "heap.h"

//--------------------------------- Task 1 ---------------------------------

TEST(IsMaxHeap, Subtestv_1) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};

    ASSERT_FALSE(isMaxHeap(array));
}

TEST(IsMaxHeap, Subtestv_2) {
    std::vector<int> array{21, 19, 18, 11, 12, 15, 16, 9, 8, 10};

    ASSERT_TRUE(isMaxHeap(array));
}

TEST(IsMaxHeap, Subtestv_3) {
    std::vector<int> array{21, 19, 18, 11, 12, 15, 16, 9, 8, 13};

    ASSERT_FALSE(isMaxHeap(array));
}

TEST(IsMaxHeap, Subtestv_4) {
    std::vector<int> array{21, 19, 18, 11, 12, 15, 16, 9, 8, 13, 11, 14, 13, 15, 8};

    ASSERT_FALSE(isMaxHeap(array));
}

TEST(IsMaxHeap, Subtestv_5) {
    std::vector<int> array{7, 9, 8, 11, 1, 36, 4, 3, 16, 17};

    ASSERT_FALSE(isMaxHeap(array));
}

TEST(IsMaxHeap, Subtestv_6) {
    std::vector<int> array{};

    ASSERT_TRUE(isMaxHeap(array));
}

//--------------------------------- Task 2 ---------------------------------
TEST(MergeKSortedArrays, Subtestv_1) {
    std::vector<std::vector<int>> array{{1, 2, 2}, {2, 5, 6}};

    std::vector<int> answer{1, 2, 2, 2, 5, 6};
    ASSERT_TRUE(mergeKSortedArrays(array) == answer);
}

TEST(MergeKSortedArrays, Subtestv_2) {
    std::vector<std::vector<int>> array{{4, 4, 4}, {1, 2, 6}};

    std::vector<int> answer{1, 2, 4, 4, 4, 6};
    ASSERT_TRUE(mergeKSortedArrays(array) == answer);
}

TEST(MergeKSortedArrays, Subtestv_3) {
    std::vector<std::vector<int>> array{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::vector<int> answer{1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_TRUE(mergeKSortedArrays(array) == answer);
}

TEST(MergeKSortedArrays, Subtestv_4) {
    std::vector<std::vector<int>> array{{}, {}, {}};

    std::vector<int> answer{};
    ASSERT_TRUE(mergeKSortedArrays(array) == answer);
}

//--------------------------------- Task 3 ---------------------------------
TEST(InorderMinIterative, Subtestv_1) {
    std::vector<int> array{16, 10, 22, 6, 12, 18, 24, 2, 8, 11, 13, 17, 21, 23, 27};
    Tree tree(array);

    ASSERT_TRUE(inorderMinIterative(tree.getRoot(), 2) == 6);
}

TEST(InorderMinIterative, Subtestv_2) {
    std::vector<int> array{16, 10, 22, 6, 12, 18, 24, 2, 8, 11, 13, 17, 21, 23, 27};
    Tree tree(array);

    ASSERT_TRUE(inorderMinIterative(tree.getRoot(), 4) == 10);
}

TEST(InorderMinIterative, Subtestv_3) {
    std::vector<int> array{16, 10, 22, 6, 12, 18, 24, 2, 8, 11, 13, 17, 21, 23, 27};
    Tree tree(array);
    
    ASSERT_TRUE(inorderMinIterative(tree.getRoot(), 8) == 16);
}

TEST(InorderMinIterative, Subtestv_4) {
    std::vector<int> array{16, 10, 22, 6, 12, 18, 24, 2, 8, 11, 13, 17, 21, 23, 27};
    Tree tree(array);

    ASSERT_TRUE(inorderMinIterative(tree.getRoot(), 9) == 17);
}

//--------------------------------- Task 4 ---------------------------------
TEST(CalculateHeightsAndBalance, Subtestv_1) {
    std::vector<int> array{16, 10, 22, 6, 12, 18, 24, 2, 8, 11, 13, 17, 21, 23, 27};
    Tree tree(array);

    ASSERT_TRUE(calculateHeightsAndBalance(tree.getRoot()) == 4);
}

TEST(CalculateHeightsAndBalance, Subtestv_2) {
    std::vector<int> array{16, 10, 22, 6, 12, 18, 24, 2, 8, 11, 13, 17, 21, 23};
    Tree tree(array);

    calculateHeightsAndBalance(tree.getRoot());
    ASSERT_TRUE(tree.getRoot()->getBalanceFactor() == 0);
}

TEST(CalculateHeightsAndBalance, Subtestv_3) {
    std::vector<int> array{16, 10, 22, 6, 12, 18, 24, 2, 8, 11, 13, 17, 21, 23};
    Tree tree(array);

    ASSERT_TRUE(calculateHeightsAndBalance(tree.getRoot()->getRightNode()) == 3);
}

TEST(CalculateHeightsAndBalance, Subtestv_4) {
    std::vector<int> array{16, 10, 22, 6, 12, 18, 24, 2, 8, 11, 13, 17, 21, 23};
    Tree tree(array);

    calculateHeightsAndBalance(tree.getRoot());
    ASSERT_TRUE(tree.getRoot()->getRightNode()->getRightNode()->getBalanceFactor() == 1);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}