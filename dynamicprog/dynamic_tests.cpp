#include "dynamic.h"

//--------------------------------- Task 1 ---------------------------------

TEST(CountSequences, Subtestv_1) {
    ASSERT_TRUE(countSequences(4) == 13);
}

TEST(CountSequences, Subtestv_2) {
    ASSERT_TRUE(countSequences(5) == 24);
}

TEST(CountSequences, Subtestv_3) {
    ASSERT_TRUE(countSequences(1) == 2);
}

TEST(CountSequences, Subtestv_4) {
    ASSERT_TRUE(countSequences(2) == 4);
}

//--------------------------------- Task 2 ---------------------------------

TEST(FindLIS, Subtestv_1) {
    std::vector<int> array{{3, 2, 8, 9, 5, 10}};
    
    ASSERT_TRUE(findLIS(array, array.size()) == 3);
}

TEST(FindLIS, Subtestv_2) {
    std::vector<int> array{{1, 2, 7, 9, 0, 10}};
    
    ASSERT_TRUE(findLIS(array, array.size()) == 4);
}

TEST(FindLIS, Subtestv_3) {
    std::vector<int> array{{8, 8, 8, 8}};
    
    ASSERT_TRUE(findLIS(array, array.size()) == 1);
}

TEST(FindLIS, Subtestv_4) {
    std::vector<int> array{{8, 7, 6, 5, 4, 3, 2, 1, 0}};
    
    ASSERT_TRUE(findLIS(array, array.size()) == 1);
}

//--------------------------------- Task 3 ---------------------------------

TEST(PascalTriangle, Subtestv_1) {
    std::vector<std::vector<size_t>> array{{{1}, 
                                            {1, 1}}};

    ASSERT_TRUE(pascalTriangle(2) == array);
}

TEST(PascalTriangle, Subtestv_2) {
    std::vector<std::vector<size_t>> array{{{1}, 
                                            {1, 1},
                                            {1, 2, 1}}};
    
    ASSERT_TRUE(pascalTriangle(3) == array);
}

TEST(PascalTriangle, Subtestv_3) {
    std::vector<std::vector<size_t>> array{{{1}, 
                                            {1, 1},
                                            {1, 2, 1},
                                            {1, 3, 3, 1}}};
    
    ASSERT_TRUE(pascalTriangle(4) == array);
}

TEST(PascalTriangle, Subtestv_4) {
    std::vector<std::vector<size_t>> array{{{1}, 
                                            {1, 1},
                                            {1, 2, 1},
                                            {1, 3, 3, 1},
                                            {1, 4, 6, 4, 1}}};

    ASSERT_TRUE(pascalTriangle(5) == array);
}

//--------------------------------- Task 4 ---------------------------------

TEST(MaxPathSum, Subtestv_1) {
    std::vector<int> array{8, 3, 2, 9, 4, 0, 0, 0, 0, 0, 11};
    Tree tree{array};

    ASSERT_TRUE(maxPathSum(tree.getRoot()) == 28);
}

TEST(MaxPathSum, Subtestv_2) {
    std::vector<int> array{8, 3, 2, 9, 4, 0, 0, 0, 7, 0, 11};
    Tree tree{array};

    ASSERT_TRUE(maxPathSum(tree.getRoot()) == 34);
}

TEST(MaxPathSum, Subtestv_3) {
    std::vector<int> array{8, 3, 2, 88, 4, 0, 0, 21, 33, 0, 11};
    Tree tree{array};

    ASSERT_TRUE(maxPathSum(tree.getRoot()) == 142);
}

TEST(MaxPathSum, Subtestv_4) {
    std::vector<int> array{8, 3, 2, 88, 0, 0, 1, 21, 0, 0, 0, 0, 0, 0, 11};
    Tree tree{array};

    ASSERT_TRUE(maxPathSum(tree.getRoot()) == 134);
}

//--------------------------------- Task 5 ---------------------------------

TEST(MaxProfit, Subtestv_1) {
    std::vector<int> array{8, 9, 3, 7, 4, 16, 12};

    ASSERT_TRUE(maxProfit(array, array.size()) == 13);
}

TEST(MaxProfit, Subtestv_2) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};

    ASSERT_TRUE(maxProfit(array, array.size()) == 6);
}

TEST(MaxProfit, Subtestv_3) {
    std::vector<int> array{8, 7, 6, 5, 4, 3, 2};

    ASSERT_TRUE(maxProfit(array, array.size()) == 0);
}

TEST(MaxProfit, Subtestv_4) {
    std::vector<int> array{8, 8, 8, 8, 8, 8};

    ASSERT_TRUE(maxProfit(array, array.size()) == 0);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}