#pragma once
#include"LinkedList.h"

const int a = rand() % 20 + 1;
const int b = rand() % 20 + 1;

const uint64_t p = 9149658775000477;

struct HashTable
{
private:

    LinkedList* bucketsArray;
    int amount;
    int M;

public:
    const float loadFactor = 0.8f;

    HashTable();

    int hash(unsigned long long key);

    void insert(unsigned long long key, Data value);

    Node* find(unsigned long long key);

    Node* erase(unsigned long long key);

    int getSize(){ return amount;}

    void increaseSize();

    ~HashTable();
};