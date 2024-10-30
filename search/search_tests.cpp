#include "search.h"

//--------------------------------- Task 1 ---------------------------------

TEST(IsSubsequenceQueue, Subtestv_1) {
    std::vector<int> a{1, 2, 3};
    std::vector<int> b{1, 2, 3, 4, 5};

    ASSERT_TRUE(isSubsequenceQueue(a, b));
}

TEST(IsSubsequenceQueue, Subtestv_2) {
    std::vector<int> a{1, 2, 6};
    std::vector<int> b{1, 2, 3, 4, 5};

    ASSERT_TRUE(!isSubsequenceQueue(a, b));
}

TEST(IsSubsequenceQueue, Subtestv_3) {
    std::vector<int> a{1, 2, 6};
    std::vector<int> b{1, 2, 3, 4, 5, 6};

    ASSERT_TRUE(isSubsequenceQueue(a, b));
}

TEST(IsSubsequenceQueue, Subtestv_4) {
    std::vector<int> a{1, 3, 5};
    std::vector<int> b{0, 1, 2, 3, 4, 6};

    ASSERT_TRUE(!isSubsequenceQueue(a, b));
}

//--------------------------------- Task 2 ---------------------------------

TEST(IsSubsequencePointers, Subtestv_1) {
    std::vector<int> a{1, 2, 3};
    std::vector<int> b{1, 2, 3, 4, 5};

    ASSERT_TRUE(isSubsequencePointers(a, a.size(), b, b.size()));
}

TEST(IsSubsequencePointers, Subtestv_2) {
    std::vector<int> a{1, 2, 6};
    std::vector<int> b{1, 2, 3, 4, 5};

    ASSERT_TRUE(!isSubsequencePointers(a, a.size(), b, b.size()));
}

TEST(IsSubsequencePointers, Subtestv_3) {
    std::vector<int> a{1, 2, 6};
    std::vector<int> b{1, 2, 3, 4, 5, 6};

    ASSERT_TRUE(isSubsequencePointers(a, a.size(), b, b.size()));
}

TEST(IsSubsequencePointers, Subtestv_4) {
    std::vector<int> a{1, 3, 5};
    std::vector<int> b{0, 1, 2, 3, 4, 6};

    ASSERT_TRUE(!isSubsequencePointers(a, a.size(), b, b.size()));
}

//--------------------------------- Task 3 ---------------------------------

TEST(IsPalindrome, Subtestv_1) {
    std::string a = "deified";

    ASSERT_TRUE(isPalindrome(a));
}

TEST(IsPalindrome, Subtestv_2) {
    std::string a = "anishka";

    ASSERT_TRUE(!isPalindrome(a));
}

TEST(IsPalindrome, Subtestv_3) {
    std::string a = "oooooooo";

    ASSERT_TRUE(isPalindrome(a));
}

TEST(IsPalindrome, Subtestv_4) {
    std::string a = "hehehehe";

    ASSERT_TRUE(!isPalindrome(a));
}

//--------------------------------- Task 4 ---------------------------------

TEST(IsPalindromeP, Subtestv_1) {
    std::string a = "deified";

    ASSERT_TRUE(isPalindrome(a, a.size()));
}

TEST(IsPalindromeP, Subtestv_2) {
    std::string a = "anishka";

    ASSERT_TRUE(!isPalindrome(a, a.size()));
}

TEST(IsPalindromeP, Subtestv_3) {
    std::string a = "oooooooo";

    ASSERT_TRUE(isPalindrome(a, a.size()));
}

TEST(IsPalindromeP, Subtestv_4) {
    std::string a = "hehehehe";

    ASSERT_TRUE(!isPalindrome(a, a.size()));
}

//--------------------------------- Task 5 ---------------------------------

TEST(BinarySearchSqrt, Subtestv_1) {
    ASSERT_TRUE(binarySearchSqrt(25) == 5);
}

TEST(BinarySearchSqrt, Subtestv_2) {
    ASSERT_TRUE(binarySearchSqrt(26) == 5);
}

TEST(BinarySearchSqrt, Subtestv_3) {
    ASSERT_TRUE(binarySearchSqrt(30) == 5);
}

TEST(BinarySearchSqrt, Subtestv_4) {
    ASSERT_TRUE(binarySearchSqrt(1) == 1);
}

TEST(BinarySearchSqrt, Subtestv_5) {
    ASSERT_TRUE(binarySearchSqrt(0) == 0);
}

//--------------------------------- Task 6 ---------------------------------

TEST(CopyTime, Subtestv_1) {
    ASSERT_TRUE(copyTime(3, 2, 3) == 5);
}

TEST(CopyTime, Subtestv_2) {
    ASSERT_TRUE(copyTime(5, 1, 2) == 4);
}

TEST(CopyTime, Subtestv_3) {
    ASSERT_TRUE(copyTime(4, 4, 5) == 12);
}

TEST(CopyTime, Subtestv_4) {
    ASSERT_TRUE(copyTime(1, 10, 15) == 10);
}

//----------------------------------- HW -----------------------------------

TEST(DeleteDuplicates, Subtestv_1) {
    std::string s = "cdffd";

    ASSERT_TRUE(deleteDuplicates(s) == "c");
}

TEST(DeleteDuplicates, Subtestv_2) {
    std::string s = "uioouiouuo";

    ASSERT_TRUE(deleteDuplicates(s) == "uiui");
}

TEST(DeleteDuplicates, Subtestv_3) {
    std::string s = "xyyx";

    ASSERT_TRUE(deleteDuplicates(s) == "");
}

TEST(DeleteDuplicates, Subtestv_4) {
    std::string s = "fqffqzzsd";

    ASSERT_TRUE(deleteDuplicates(s) == "fsd");
}

//--------------------------------------------------------------------------


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}