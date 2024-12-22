#include "tree.h"

//--------------------------------- Task 1 ---------------------------------

TEST(SymmetricTree, Subtestv_1) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    Tree tree(array);

    ASSERT_FALSE(isSymmetric(tree.getRoot()));
}

TEST(SymmetricTree, Subtestv_2) {
    std::vector<int> array{1, 2, 2, 2, 2, 2, 2};
    Tree tree(array);

    ASSERT_TRUE(isSymmetric(tree.getRoot()));
}

TEST(SymmetricTree, Subtestv_3) {
    std::vector<int> array{1, 2, 2, 2, 2, 2};
    Tree tree(array);

    ASSERT_FALSE(isSymmetric(tree.getRoot()));
}

TEST(SymmetricTree, Subtestv_4) {
    std::vector<int> array{1, 2, 2, 3, 4, 4, 3};
    Tree tree(array);

    ASSERT_TRUE(isSymmetric(tree.getRoot()));
}

//--------------------------------- Task 2 ---------------------------------

TEST(SymmetricTreeDFS, Subtestv_1) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    Tree tree(array);

    ASSERT_FALSE(isSymmetricDFS(tree.getRoot()));
}

TEST(SymmetricTreeDFS, Subtestv_2) {
    std::vector<int> array{1, 2, 2, 2, 2, 2, 2};
    Tree tree(array);

    ASSERT_TRUE(isSymmetricDFS(tree.getRoot()));
}

TEST(SymmetricTreeDFS, Subtestv_3) {
    std::vector<int> array{1, 2, 2, 2, 2, 2};
    Tree tree(array);

    ASSERT_FALSE(isSymmetricDFS(tree.getRoot()));
}

TEST(SymmetricTreeDFS, Subtestv_4) {
    std::vector<int> array{1, 2, 2, 3, 4, 4, 3};
    Tree tree(array);

    ASSERT_TRUE(isSymmetricDFS(tree.getRoot()));
}

//--------------------------------- Task 3 ---------------------------------

TEST(MinDepth, Subtestv_1) {
    std::vector<int> array{1};
    Tree tree(array);

    ASSERT_TRUE(minDepth(tree.getRoot()) == 1);
}

TEST(MinDepth, Subtestv_2) {
    std::vector<int> array{1, 2, 3};
    Tree tree(array);

    ASSERT_TRUE(minDepth(tree.getRoot()) == 2);
}

TEST(MinDepth, Subtestv_3) {
    std::vector<int> array{1, 2};
    Tree tree(array);

    ASSERT_TRUE(minDepth(tree.getRoot()) == 1);
}

TEST(MinDepth, Subtestv_4) {
    std::vector<int> array{};
    Tree tree(array);

    ASSERT_TRUE(minDepth(tree.getRoot()) == 0);
}

//--------------------------------- Task 4 ---------------------------------

TEST(MaxMinMultiplication, Subtestv_1) {
    std::vector<int> array{16, 12, 18, 11, 15, 17, 21};
    Tree tree(array);

    ASSERT_TRUE(maxMinMultiplication(tree.getRoot()) == 231);
}

TEST(MaxMinMultiplication, Subtestv_2) {
    std::vector<int> array{16, 12, 18, 11, 15, 17};
    Tree tree(array);

    ASSERT_TRUE(maxMinMultiplication(tree.getRoot()) == 198);
}

TEST(MaxMinMultiplication, Subtestv_3) {
    std::vector<int> array{16, 12, 18, 11, 15};
    Tree tree(array);

    ASSERT_TRUE(maxMinMultiplication(tree.getRoot()) == 198);
}

//--------------------------------- Task 5 ---------------------------------

TEST(IsSameTree, Subtestv_1) {
    std::vector<int> array{16, 12, 18, 11, 15};
    Tree tree1(array);
    Tree tree2(array);

    ASSERT_TRUE(isSameTree(tree1.getRoot(), tree2.getRoot()));
}

TEST(IsSameTree, Subtestv_2) {
    std::vector<int> array1{16, 12, 18, 11, 15};
    std::vector<int> array2{16, 12, 18, 11};
    Tree tree1(array1);
    Tree tree2(array2);

    ASSERT_FALSE(isSameTree(tree1.getRoot(), tree2.getRoot()));
}

TEST(IsSameTree, Subtestv_3) {
    std::vector<int> array1{};
    std::vector<int> array2{};
    Tree tree1(array1);
    Tree tree2(array2);

    ASSERT_TRUE(isSameTree(tree1.getRoot(), tree2.getRoot()));
}

TEST(IsSameTree, Subtestv_4) {
    std::vector<int> array1{2};
    std::vector<int> array2{1};
    Tree tree1(array1);
    Tree tree2(array2);

    ASSERT_FALSE(isSameTree(tree1.getRoot(), tree2.getRoot()));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}