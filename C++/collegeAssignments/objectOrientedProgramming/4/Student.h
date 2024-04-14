#pragma once
#include "Person.h"
class Student :
    public Person {
    int an;
    std::string grupa;
    bool bursier;
    float valBursa;
public:
    Student(std::string firstName, std::string lastName, std::string CNP,
        int an = 1, std::string grupa = "A", bool bursier = false, float valBursa = 0);
    std::string getGrupa();
    void print();
};

