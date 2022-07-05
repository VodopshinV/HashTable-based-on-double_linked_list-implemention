#pragma once
#include"Node.h"

struct LinkedList
{
private:
    Node* head;
    Node *tail;

public:

    LinkedList() { head = nullptr; tail = nullptr; };

    Node* head_hunt() { return this->head; }

    void push(Data building, unsigned long long key);

    Node* find(unsigned long long key);

    Node* pop(unsigned long long key);
};
