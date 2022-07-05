#include"LinkedList.h"

Node* LinkedList::find(unsigned long long key)
{
    Node* node = head;
    while (node && node->key != key)
    {
        node = node->next;
    }
    return node;
}

void LinkedList::push(Data building, unsigned long long key)
{
    Node* newNode = new Node(key, building);

    newNode->prev = tail;
    if (!tail)
    {
        tail = newNode;
        head = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* LinkedList::pop(unsigned long long key)
{
    Node* node = find(key);

    if (!node)
    {
        return nullptr;
    }

    if (node == head)
    {
        if (head->next)
        {
            head->next->prev = nullptr;
        }    
        head = head->next;
        return node;
    }

    if (node == tail)
    {
        tail->prev->next = nullptr;
        tail = tail->prev;
        return node;
    }


    node->prev->next = node->next;
    node->next->prev = node->prev;

    return node;
}

