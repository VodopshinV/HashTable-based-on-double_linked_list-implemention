#include"HashTable.h"


HashTable::HashTable()
{
    M = 8;
    bucketsArray = new LinkedList[M];
    amount = 0;
}

int HashTable::hash(unsigned long long key)
{
    return ((a * key + b) % p) % M;
}

void HashTable::insert(unsigned long long key, Data value)
{
    Node* newNode = bucketsArray[hash(key)].find(key);

    if (newNode)
    {
        newNode->building = value;
        return;
    }

    bucketsArray[hash(key)].push(value, key);
    amount++;

    if ((float)(amount) / (float)(M) > loadFactor)
    {
        increaseSize();
    }      
}

Node* HashTable::find(unsigned long long key)
{
    return bucketsArray[hash(key)].find(key);
}

Node* HashTable::erase(unsigned long long key)
{
    Node* node = bucketsArray[hash(key)].pop(key);

    if (node)
    {
        amount--;
    }      
    return node;
}

void HashTable::increaseSize()
{
    M *= 2;
    amount = 0;

    LinkedList* DeleteList = bucketsArray;
    bucketsArray = new LinkedList[M];

    for (int i = 0; i < M/2; i++)
    {
        if (DeleteList[i].head_hunt() != nullptr)
        {

            Node* node = DeleteList[i].head_hunt();

            while (node)
            {
                insert(node->key, node->building);
                node = node->next;
            }
        }
    }
    delete[] DeleteList;
}

HashTable::~HashTable()
{
    for (int i = 0; i < M; i++)
    {
        if (bucketsArray[i].head_hunt())
        {
            Node* node = nullptr;
            Node* head = bucketsArray[i].head_hunt();

            while (head)
            {
                node = head;
                head = head->next;
                delete node;
            }
        }
    }
    delete[] bucketsArray;
}
