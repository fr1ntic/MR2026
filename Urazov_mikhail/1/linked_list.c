#include <stdlib.h>

#include "linked_list.h"

Node* create_list() {
    Node* list = malloc(sizeof(Node));
    list->next = nullptr;
    list->data = nullptr;
    return list;
}

void* get(Node* list, int index) {
    Node* curnode = list;
    for(int i = 0; i < index; i++) {
        curnode = curnode->next;
        if (curnode == nullptr) {
            return nullptr;
        }
    }
    return curnode->data;
}

void push_back(Node* list, void* data) {
    Node* curnode = list;
    while (curnode->data != nullptr) {
        Node* next = curnode->next;
        if(next == nullptr) {
            next = create_list();
            curnode->next = next;
        }
        curnode = next;
    }
    curnode->data = data;
}

void delete_list(Node* list) {
    Node* curnode = list;
    Node* nextnode = curnode->next;
    while (nextnode != nullptr) {
        free(curnode);
        curnode = nextnode;
        nextnode = curnode->next;
    }
}

int len(Node* list) {
    int lenght = 0;
    Node* curnode = list;
    while (curnode->data != nullptr) {
        lenght += 1;
        if (curnode->next == nullptr) {
            break;
        }
        curnode = curnode->next;
    }
    return lenght;
}