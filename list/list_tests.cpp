#include "list.h"

//--------------------------------- Task 1 ---------------------------------

TEST(HasCicle, Subtestv_1) {
    List_t list{};
    for(int i = -9; i < 10; ++i) {
        list.addNode(i);
    }
    
    Node_t* list_it = list.head;
    for(int i = 0; i < 9; ++i) {
        list_it = list_it->next;
    }
    list.tail->next = list_it;

    ASSERT_TRUE(hasCicle(list.head));
}

TEST(HasCicle, Subtestv_2) {
    List_t list{};
    for(int i = -9; i < 10; ++i) {
        list.addNode(i);
    }

    ASSERT_FALSE(hasCicle(list.head));
}

TEST(HasCicle, Subtestv_3) {
    List_t list{};
    for(int i = -9; i < 10; ++i) {
        list.addNode(i);
    }

    list.tail->next = list.head;

    ASSERT_TRUE(hasCicle(list.head));
}

//--------------------------------- Task 2 ---------------------------------

TEST(ReverseLinkedList, Subtestv_1) {
    List_t list{};
    for(int i = 0; i < 10; ++i) {
        if(i % 2 == 0) {
            list.addNode(i);
        }
    }

    list.head = reverseLinkedList(list.head);

    List_t answer{};
    for(int i = 9; i > -1; --i) {
        if(i % 2 == 0) {
            answer.addNode(i);
        }
    }
    ASSERT_TRUE(list == answer);
}

TEST(ReverseLinkedList, Subtestv_2) {
    List_t list{};
    for(int i = -9; i < 10; ++i) {
        list.addNode(i);
    }

    list.head = reverseLinkedList(list.head);

    List_t answer{};
    for(int i = 9; i > -10; --i) {
        answer.addNode(i);
    }
    ASSERT_TRUE(list == answer);
}

TEST(ReverseLinkedList, Subtestv_3) {
    List_t list{};
    for(int i = -9; i < 10; ++i) {
        if(i % 2 == 0) {
            list.addNode(i);
        }
    }

    list.head = reverseLinkedList(list.head);

    List_t answer{};
    for(int i = 9; i > -10; --i) {
        if(i % 2 == 0) {
            answer.addNode(i);
        }
    }
    ASSERT_TRUE(list == answer);
}

//--------------------------------- Task 3 ---------------------------------

TEST(MiddleNode, Subtestv_1) {
    List_t list{};
    for(int i = 1; i <= 5; ++i) {
        list.addNode(i);
    }

    ASSERT_TRUE(middleNode(list.head)->value == 3);
}

TEST(MiddleNode, Subtestv_2) {
    List_t list{};
    for(int i = -9; i < 10; ++i) {
        list.addNode(i);
    }

    ASSERT_TRUE(middleNode(list.head)->value == 0);
}

TEST(MiddleNode, Subtestv_3) {
    List_t list{};
    for(int i = 0; i <= 9; ++i) {
        list.addNode(i);
    }

    ASSERT_TRUE(middleNode(list.head)->value == 5);
}

//--------------------------------- Task 4 ---------------------------------

TEST(RemoveElements, Subtestv_1) {
    List_t list{};
    for(int i = 0; i < 10; ++i) {
        list.addNode(i);
    }

    list.head = removeElement(list.head, 1);

    List_t answer{};
    for(int i = 0; i < 10; ++i) {
        if(i != 1) {
            answer.addNode(i);
        }
    }
    ASSERT_TRUE(list == answer);
}

TEST(RemoveElements, Subtestv_2) {
    List_t list{};
    for(int i = 0; i < 10; ++i) {
        list.addNode(i);
    }

    list.head = removeElement(list.head, 0);

    List_t answer{};
    for(int i = 1; i < 10; ++i) {
        answer.addNode(i);
    }
    ASSERT_TRUE(list == answer);
}

TEST(RemoveElements, Subtestv_3) {
    List_t list{};
    for(int i = 0; i < 10; ++i) {
        list.addNode(i);
    }

    ASSERT_FALSE(removeElement(list.head, 10));
}

//----------------------------------- HW -----------------------------------

TEST(SortListMerge, Subtestv_1) {
    List_t list1{};
    std::vector<int> nums1 {3, 6, 8};
    for(auto i: nums1) {
        list1.addNode(i);
    }

    List_t list2{};
    std::vector<int> nums2 {4, 7, 9, 11};
    for(auto i: nums2) {
        list2.addNode(i);
    }

    List_t list = sortListMerge(list1, list2);

    List_t answer{};
    std::vector<int> ans_nums {3, 4, 6, 7, 8, 9, 11};
    for(auto i: ans_nums) {
        answer.addNode(i);
    }
    ASSERT_TRUE(list == answer);
}

TEST(SortListMerge, Subtestv_2) {
    List_t list1{};
    std::vector<int> nums1 {1, 3, 5, 7, 9};
    for(auto i: nums1) {
        list1.addNode(i);
    }

    List_t list2{};
    std::vector<int> nums2 {2, 4, 6, 8, 10};
    for(auto i: nums2) {
        list2.addNode(i);
    }

    List_t list = sortListMerge(list1, list2);

    List_t answer{};
    std::vector<int> ans_nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(auto i: ans_nums) {
        answer.addNode(i);
    }
    ASSERT_TRUE(list == answer);
}

TEST(SortListMerge, Subtestv_3) {
    List_t list1{};
    std::vector<int> nums1 {6, 7, 8, 9, 10};
    for(auto i: nums1) {
        list1.addNode(i);
    }

    List_t list2{};
    std::vector<int> nums2 {1, 2, 3, 4, 5};
    for(auto i: nums2) {
        list2.addNode(i);
    }

    List_t list = sortListMerge(list1, list2);

    List_t answer{};
    std::vector<int> ans_nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(auto i: ans_nums) {
        answer.addNode(i);
    }
    ASSERT_TRUE(list == answer);
}

//--------------------------------------------------------------------------


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}