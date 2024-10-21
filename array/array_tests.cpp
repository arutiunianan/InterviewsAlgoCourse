#include "array.h"

//--------------------------------- Task 1 ---------------------------------
TEST(ReverseArray, Subtestv_1) {
    std::vector<int> array{1, 2, 3, 4, 5, 6};
    int n = array.size();
    reverseArray(array, n);

    std::vector<int> answer{6, 5, 4, 3, 2, 1};
    ASSERT_TRUE(array == answer);
}

TEST(ReverseArray, Subtestv_2) {
    std::vector<int> array{1, 2, 3, 4, 5};
    int n = array.size();
    reverseArray(array, n);

    std::vector<int> answer{5, 4, 3, 2, 1};
    ASSERT_TRUE(array == answer);
}

TEST(ReverseArray, Subtestv_3) {
    std::vector<int> array{3, 8, 6, 9, 9, 8, 6};
    int n = array.size();
    reverseArray(array, n);

    std::vector<int> answer{6, 8, 9, 9, 6, 8, 3};
    ASSERT_TRUE(array == answer);
}

//--------------------------------- Task 2 ---------------------------------
TEST(ReverseArrayPart, Subtestv_1) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    int n = array.size();
    int k = 3;
    reverseArrayPart(array, n, k);

    std::vector<int> answer{5, 6, 7, 1, 2, 3, 4};
    ASSERT_TRUE(array == answer);
}


TEST(ReverseArrayPart, Subtestv_2) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    int n = array.size();
    int k = n + 1;
    reverseArrayPart(array, n, k);

    std::vector<int> answer{7, 1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(array == answer);
}

TEST(ReverseArrayPart, Subtestv_3) {
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7};
    int n = array.size();
    int k = 0;
    reverseArrayPart(array, n, k);

    std::vector<int> answer{1, 2, 3, 4, 5, 6, 7};
    ASSERT_TRUE(array == answer);
}

//--------------------------------- Task 3 ---------------------------------

TEST(MergeSortedArrays1, Subtestv_1) {
    std::vector<int> array1{1, 3, 5, 7};
    std::vector<int> array2{2, 4, 6};
    int n = array1.size();
    int m = array2.size();
    std::vector<int> result = mergeSortedArrays(array1, n, array2, m);

    std::vector<int> answer{1, 2, 3, 4, 5, 6, 7};
    ASSERT_TRUE(result == answer);
}

TEST(MergeSortedArrays1, Subtestv_2) {
    std::vector<int> array1{1, 2, 3};
    std::vector<int> array2{4, 5, 6, 7};
    int n = array1.size();
    int m = array2.size();
    std::vector<int> result = mergeSortedArrays(array1, n, array2, m);

    std::vector<int> answer{1, 2, 3, 4, 5, 6, 7};
    ASSERT_TRUE(result == answer);
}

TEST(MergeSortedArrays1, Subtestv_3) {
    std::vector<int> array1{4, 5, 6, 7};
    std::vector<int> array2{1, 2, 3};
    int n = array1.size();
    int m = array2.size();
    std::vector<int> result = mergeSortedArrays(array1, n, array2, m);

    std::vector<int> answer{1, 2, 3, 4, 5, 6, 7};
    ASSERT_TRUE(result == answer);
}

//--------------------------------- Task 4 ---------------------------------

TEST(MergeSortedArrays2, Subtestv_1) {
    std::vector<int> array1{1, 3, 5, 7};
    std::vector<int> array2{2, 4, 6};
    int n = array1.size();
    int m = array2.size();
    array1.resize(n + m, 0);
    merge(array1, n, array2, m);

    std::vector<int> answer{1, 2, 3, 4, 5, 6, 7};
    ASSERT_TRUE(array1 == answer);
}

TEST(MergeSortedArrays2, Subtestv_2) {
    std::vector<int> array1{1, 2, 3};
    std::vector<int> array2{4, 5, 6, 7};
    int n = array1.size();
    int m = array2.size();
    array1.resize(n + m, 0);
    merge(array1, n, array2, m);

    std::vector<int> answer{1, 2, 3, 4, 5, 6, 7};
    ASSERT_TRUE(array1 == answer);
}

TEST(MergeSortedArrays2, Subtestv_3) {
    std::vector<int> array1{4, 5, 6, 7};
    std::vector<int> array2{1, 2, 3};
    int n = array1.size();
    int m = array2.size();
    array1.resize(n + m, 0);
    merge(array1, n, array2, m);

    std::vector<int> answer{1, 2, 3, 4, 5, 6, 7};
    ASSERT_TRUE(array1 == answer);
}

//--------------------------------- Task 5 ---------------------------------

TEST(EvenFirst, Subtestv_1) {
    std::vector<int> array{3, 2, 4, 1, 11, 8, 9};
    int n = array.size();
    evenFirst(array, n);

    std::vector<int> answer{2, 4, 8, 1, 11, 3, 9};
    ASSERT_TRUE(array == answer);
}

TEST(EvenFirst, Subtestv_2) {
    std::vector<int> array{0, 2, 4, 6, 8, 1, 3, 5, 7};
    int n = array.size();
    evenFirst(array, n);

    std::vector<int> answer{0, 2, 4, 6, 8, 1, 3, 5, 7};
    ASSERT_TRUE(array == answer);
}

TEST(EvenFirst, Subtestv_3) {
    std::vector<int> array{1, 3, 5, 7, 0, 2, 4, 6, 8};
    int n = array.size();
    evenFirst(array, n);

    std::vector<int> answer{0, 2, 4, 6, 8, 3, 5, 7, 1};
    ASSERT_TRUE(array == answer);
}

//----------------------------------- HW -----------------------------------

TEST(ZerosAtTheEnd, Subtestv_1) {
    std::vector<int> array{0, 0, 1, 0, 3, 12};
    int n = array.size();
    zerosAtTheEnd(array, n);

    std::vector<int> answer{1, 3, 12, 0, 0, 0};
    ASSERT_TRUE(array == answer);
}

TEST(ZerosAtTheEnd, Subtestv_2) {
    std::vector<int> array{0, 33, 57, 88, 60, 0, 0, 80, 99};
    int n = array.size();
    zerosAtTheEnd(array, n);

    std::vector<int> answer{33, 57, 88, 60, 80, 99, 0, 0, 0};
    ASSERT_TRUE(array == answer);
}

TEST(ZerosAtTheEnd, Subtestv_3) {
    std::vector<int> array{0, 0, 0, 18, 16, 0, 0, 77, 99};
    int n = array.size();
    zerosAtTheEnd(array, n);

    std::vector<int> answer{18, 16, 77, 99, 0, 0, 0, 0, 0};
    ASSERT_TRUE(array == answer);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}