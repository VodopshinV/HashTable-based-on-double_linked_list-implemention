#pragma once
#include"UniversityBuildingStruct.h"

struct Node
{
    Node* prev;
    Node* next;
    unsigned long long key;
    Data building;

    Node(unsigned long long key_, Data building_)
    {
        key = key_;
        building = building_;
        next = prev = nullptr;
    }
};