#include <iostream>
#include <vector>
#include "Work.h"

int main()
{
    std::vector<Person*> same;
    Person me("Efe", "Dikmen", 1999);
    Employee me1("Efe", "Dikmen", 1999, 23454.4, 312);
    Manager me2("Efe", "Dikmen", 1999, 23454.4, 312, 0.15);
    Clerk me3("Efe", "Dikmen", 1990, 1000, 201, &me2);
    Manager me4("Efe", "Dikmen", 2000, 132.4, 312, 0.15);
    me3.set(&me4);
    same.push_back(&me);
    same.push_back(&me1);
    same.push_back(&me2);
    same.push_back(&me3);
    for (int i = 0; i<4; i++)
    { same[i]->print(); }
    return 0;
}