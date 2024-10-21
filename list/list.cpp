#include "list.h"

//--------------------------------- Task 1 ---------------------------------
bool hasCicle(Node_t* head) {
    if(head == nullptr || head->next == nullptr) {
        return false;
    }

    Node_t* slow = head;
    Node_t* fast = head->next;

    while(slow != fast) {
        if(fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}


//--------------------------------- Task 2 ---------------------------------
Node_t* reverseLinkedList(Node_t* head) {
    Node_t* prev = nullptr;
    Node_t* current = head;

    while(current != nullptr) {
        Node_t* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}


//--------------------------------- Task 3 ---------------------------------
Node_t* middleNode(Node_t* head) {
    Node_t* slow = head;
    Node_t* fust = head;

    while(fust != nullptr && fust->next != nullptr) {
        slow = slow->next;
        fust = fust->next->next;
    }
    return slow;
}


//--------------------------------- Task 4 ---------------------------------
Node_t* removeNode(Node_t* head, int value) {
    Node_t* dummy = new Node_t(value, head);
    Node_t* prev = dummy;
    Node_t* current = head;

    while(current != nullptr) {
        if(current->value == value) {
            prev->next = current->next;
            return current;
        }
        else {
            prev = current;
        }
        current = current->next;
    }
    return nullptr;
}

Node_t* removeElement(Node_t* head, int value) {
    Node_t* Node = removeNode(head, value);
    if(Node == head) {
        return head->next;
    }
    if(Node != nullptr) {
        return head;
    }
    return Node;
}


//----------------------------------- HW -----------------------------------
List_t sortListMerge(List_t list1, List_t list2) {
    Node_t* i = list1.head;
    Node_t* j = list2.head;

    List_t new_list{};

    if(i->value <= j->value) {
        new_list.head = i;
        i = i->next;
    }
    else {
        new_list.head = j;
        j = j->next;
    }
    Node_t* k = new_list.head;

    while(i != nullptr && j != nullptr) {
        if(i->value <= j->value) {
            k->next = i;
            i = i->next;
        }
        else {
            k->next = j;
            j = j->next;
        }
        k = k->next;
    }

    while(i != nullptr) {
        k->next = i;
        i = i->next;
        k = k->next;
    }
    while(j != nullptr) {
        k->next = j;
        j = j->next;
        k = k->next;
    }
    return new_list;
}

//--------------------------------------------------------------------------