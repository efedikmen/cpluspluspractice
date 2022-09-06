#include <iostream>
#include "Work.h"

//functions for Person
Person::Person(std::string fname, std::string lname, int year)
{
    name = fname;
    surname = lname;
    birth_year = year;
};
int Person::get_birth() const
{ return birth_year; };
std::string Person::get_name() const
{ return name + " " + surname; };
void Person::print() const
{
    std::cout << "Person" << std::endl;
    std::cout << "Name: " << get_name() << std::endl;
    std::cout << "Birth Year: " << birth_year << std::endl;
};

//functions for Employee
Employee::Employee(std::string fname, std::string lname, int year, double sal, int date):Person{fname, lname, year}
{
    name = fname;
    surname = lname;
    birth_year = year;
    salary = sal;
    employment_date = date;
};
double Employee::get_salary() const
{ return salary; };
void Employee::set_salary(double sal)
{ salary = sal; };
void Employee::print() const
{
    std::cout << "Employee"<< std::endl;
    std::cout << "Name: "<< get_name() << std::endl;
    std::cout << "Birth Year: " << birth_year << std::endl;
    std::cout << "Salary: $" << get_salary() << std::endl;
    std::cout << "Employment date(monthday): " << employment_date << std::endl;
};

//functions for Manager
Manager::Manager(std::string fname, std::string lname, int year, double sal, int date, double c):Employee{fname, lname, year, sal, date}
{
    name = fname;
    surname = lname;
    birth_year = year;
    salary = sal;
    employment_date = date;
    com = c;
};
void Manager::set_com(double c)
{  com = c; };
double Manager::get_com() const
{ return com; };
void Manager::print() const
{
    std::cout << "Manager"<< std::endl;
    std::cout << "Name: "<< get_name() << std::endl;
    std::cout << "Birth Year: " << birth_year << std::endl;
    std::cout << "Salary: $" << get_salary() << std::endl;
    std::cout << "Employment date(monthday): " << employment_date << std::endl;
    std::cout << "Comission: " << get_com() * 100 << '%' << std::endl;
};

//functions for Clerk
Clerk::Clerk(std::string fname, std::string lname, int year, double sal, int date, Manager *man):Employee{fname, lname, year, sal, date}
{
    name = fname;
    surname = lname;
    birth_year = year;
    salary = sal;
    employment_date = date;
    m = man;
};
void Clerk::print() const
{
    std::cout << "Clerk"<< std::endl;
    std::cout << "Name: "<< get_name() << std::endl;
    std::cout << "Birth Year: " << birth_year << std::endl;
    std::cout << "Salary: $" << get_salary() << std::endl;
    std::cout << "Employment date(monthday): " << employment_date << std::endl;
    std::cout << "Details about the manager of this clerk:" << std::endl;
    m->print();
};
void Clerk::set(const Manager* man)
{
    *m = *man;
};