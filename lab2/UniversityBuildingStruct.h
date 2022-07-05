#pragma once
#include<string>

const std::string streets[] = {"Akademika Yanhelya,", "Solomenska,", "Metalistiv,", "Oleksy Tykhoho,", "Borshahivska,"};

struct Data
{
    std::string adress;
    int number;
    bool fire_protection;

    Data()
    {
        adress = streets[rand() % 5] + std::to_string(rand() % 100);
        number = rand() % 25 + 1;
        fire_protection = rand() % 2;
    }
  
};