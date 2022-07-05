#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <unordered_map>

#include"UniversityBuildingStruct.h"
#include"Node.h"
#include"LinkedList.h"
#include"HashTable.h"

using namespace std;

const int key_length = 13;

bool testHashTable();

uint64_t KeyRandomize();

int main()
{
    srand(time(nullptr));

    testHashTable();

    return 0;
}


uint64_t KeyRandomize()
{
    uint64_t key = 0;

    for (int i = 0; i < key_length-1; i++)
    {
        key += (rand() % 10) * pow(10,i);
    }
    key += (rand() % 9+1) * pow(10,key_length-1);

    return key;
}


bool testHashTable()
{
    const int iters = 500000;
    const int keysAmount = iters * 1;

    // generate random keys:
    long long* keys = new long long[keysAmount];

    long long* keysToInsert = new long long[iters];
    long long* keysToErase = new long long[iters];
    long long* keysToFind = new long long[iters];

    for (int i = 0; i < keysAmount; i++)
    {
        keys[i] = KeyRandomize();
    }
    for (int i = 0; i < iters; i++)
    {
        keysToInsert[i] = keys[KeyRandomize() % keysAmount];
        keysToErase[i] = keys[KeyRandomize() % keysAmount];
        keysToFind[i] = keys[KeyRandomize() % keysAmount];
    }

    // test my HashTable:
    HashTable hashTable;

    clock_t myStart = clock();
    for (int i = 0; i < iters; i++)
    {
        hashTable.insert(keysToInsert[i], Data());
    }
    int myInsertSize = hashTable.getSize();
    for (int i = 0; i < iters; i++)
    {
        hashTable.erase(keysToErase[i]);
    }
    int myEraseSize = hashTable.getSize();
    int myFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
        if (hashTable.find(keysToFind[i]) != nullptr)
        {
            myFoundAmount++;
        }
    }
    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

    // test STL hash table:
    unordered_map<unsigned long long, Data> unorderedMap;

    clock_t stlStart = clock();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.insert({ keysToInsert[i], Data() });
    }
    int stlInsertSize = unorderedMap.size();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.erase(keysToErase[i]);
    }
    int stlEraseSize = unorderedMap.size();
    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
        if (unorderedMap.find(keysToFind[i]) != unorderedMap.end())
        {
            stlFoundAmount++;
        }
    }
    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;

    cout << "My HashTable:" << endl;
    cout << "Time: " << myTime << ", size: " << myInsertSize << " - " << myEraseSize << ", found amount: " << myFoundAmount << endl;
    cout << "STL unordered_map:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlInsertSize << " - " << stlEraseSize << ", found amount: " << stlFoundAmount << endl
        << endl;

    delete[] keys;
    delete[] keysToInsert;
    delete[] keysToErase;
    delete[] keysToFind;

    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount == stlFoundAmount)
    {
        cout << "The lab is completed" << endl;
        return true;
    }

    cerr << ":(" << endl;
    return false;
}