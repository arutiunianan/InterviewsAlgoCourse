#include "sort.h"

//--------------------------------- Task 1 ---------------------------------
TEST(SortShell, Subtestv_1) {
    std::vector<int> array{6, 5, 4, 3, 2, 1};
    sortShell(array, array.size());

    std::vector<int> answer{1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(array == answer);
}

TEST(SortShell, Subtestv_2) {
    std::vector<int> array{0, 6, 22, 55, 3, 9, 22, 3, 1, -1};
    sortShell(array, array.size());

    std::vector<int> answer{-1, 0, 1, 3, 3, 6, 9, 22, 22, 55};
    ASSERT_TRUE(array == answer);
}

TEST(SortShell, Subtestv_3) {
    std::vector<int> array{12, 11, 9, 8, 16, 24, 19, 3, 7, 88, 72, 63};
    sortShell(array, array.size());

    std::vector<int> answer{3, 7, 8, 9, 11, 12, 16, 19, 24, 63, 72, 88};
    ASSERT_TRUE(array == answer);
}


//--------------------------------- Task 2 ---------------------------------
TEST(FeedAnimals, Subtestv_1) {
    std::vector<int> animals{3, 4, 7};
    std::vector<int> food{8, 1, 2};

    ASSERT_TRUE(feedAnimals(animals, animals.size(), food, food.size()) == 1);
}

TEST(FeedAnimals, Subtestv_2) {
    std::vector<int> animals{3, 8, 1, 4};
    std::vector<int> food{1, 1, 2};

    ASSERT_TRUE(feedAnimals(animals, animals.size(), food, food.size()) == 1);
}

TEST(FeedAnimals, Subtestv_3) {
    std::vector<int> animals{1, 2, 2};
    std::vector<int> food{7, 1};

    ASSERT_TRUE(feedAnimals(animals, animals.size(), food, food.size()) == 2);
}

TEST(FeedAnimals, Subtestv_4) {
    std::vector<int> animals{8, 2, 3, 2};
    std::vector<int> food{1, 4, 3, 8};

    ASSERT_TRUE(feedAnimals(animals, animals.size(), food, food.size()) == 3);
}


//--------------------------------- Task 3 ---------------------------------
TEST(ExtraLetter, Subtestv_1) {
    std::string a = "uio";
    std::string b = "oeiu";

    ASSERT_TRUE(extraLetter(a, b) == "e");
}

TEST(ExtraLetter, Subtestv_2) {
    std::string a = "fe";
    std::string b = "efo";

    ASSERT_TRUE(extraLetter(a, b) == "o");
}

TEST(ExtraLetter, Subtestv_3) {
    std::string a = "ab";
    std::string b = "ab";

    ASSERT_TRUE(extraLetter(a, b) == "");
}

TEST(ExtraLetter, Subtestv_4) {
    std::string a = "bbb";
    std::string b = "bbbb";

    ASSERT_TRUE(extraLetter(a, b) == "b");
}


//--------------------------------- Task 4 ---------------------------------
TEST(TwoSum, Subtestv_1) {
    std::vector<int> array{0, 2, 4, 5, 6, 8};
    int target = 9;

    std::pair<int, int> answer{4, 5};
    ASSERT_TRUE(twoSum(array, array.size(), target) == answer);
}

TEST(TwoSum, Subtestv_2) {
    std::vector<int> array{0, 1, 3, 4, 5, 7};
    int target = 8;

    std::pair<int, int> answer{1, 7};
    ASSERT_TRUE(twoSum(array, array.size(), target) == answer);
}

TEST(TwoSum, Subtestv_3) {
    std::vector<int> array{0, 5, 5, 3, 4, 8, 1};
    int target = 6;

    std::pair<int, int> answer{5, 1};
    ASSERT_TRUE(twoSum(array, array.size(), target) == answer);
}


//----------------------------------- HW -----------------------------------
TEST(GroupAnagrams, Subtestv_1) {
    std::vector<std::string> array{"eat","tea","tan","ate","nat","bat"};

    std::vector<std::vector<std::string>> result = groupAnagrams(array, array.size());
    std::vector<std::vector<std::string>> answer{std::vector<std::string>{"bat"},
                                                 std::vector<std::string>{"tan", "nat"},
                                                 std::vector<std::string>{"eat", "tea", "ate"}};
    ASSERT_TRUE(result == answer);
}

TEST(GroupAnagrams, Subtestv_2) {
    std::vector<std::string> array{"won","now","aaa","ooo","ooo"};

    std::vector<std::vector<std::string>> result = groupAnagrams(array, array.size());
    std::vector<std::vector<std::string>> answer{std::vector<std::string>{"aaa"},
                                                 std::vector<std::string>{"ooo", "ooo"},
                                                 std::vector<std::string>{"won", "now"}};
    ASSERT_TRUE(result == answer);
}

//--------------------------------------------------------------------------


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}