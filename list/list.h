#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <gtest/gtest.h>
#include <vector>



struct Node_t {
    int value;
    Node_t* next;

    Node_t(int v): value(v), next(nullptr) {}
    Node_t(int v, Node_t* n): value(v), next(n) {}
};


struct List_t {
    Node_t* head;
    Node_t* tail; 

    List_t(): head(nullptr), tail(nullptr) {}

    void addNode(int value) {

        if(head == nullptr) {
            head = new Node_t(value);
            tail = head;
        }
        else {
            tail->next = new Node_t(value);
            tail = tail->next;
        }
    }

    void print() {
        Node_t* list_it = head;
        //std::cout << size << "\n";
        while(list_it != nullptr) {
            std::cout << list_it->value << " ";
            list_it = list_it->next;
        }
        std::cout << "\n\n\n";
    }

    bool operator==(List_t list) {
        Node_t* list_it1 = head;
        Node_t* list_it2 = list.head;
        while(list_it1 != nullptr) {
            if(list_it1->value != list_it2->value) {
                return false;
            }
            list_it1 = list_it1->next;
            list_it2 = list_it2->next;
        }
        if(list_it2 != nullptr) {
            return false;
        }
        return true;
    }
};


bool hasCicle(Node_t* head);
Node_t* reverseLinkedList(Node_t* head);
Node_t* middleNode(Node_t* head);
Node_t* removeElement(Node_t* head, int value);
List_t sortListMerge(List_t list1, List_t list2);

#endif // #define LIST_H_