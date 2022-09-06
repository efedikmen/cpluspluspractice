#pragma once
#include <string>

class Person
{
    protected:
        std::string name;
        std::string surname;
        int birth_year;
    public:
        Person(std::string fname, std::string lname, int year);
        ~Person(){};
        virtual void print() const;
        int get_birth() const;
        std::string get_name() const;
};   

class Employee: public Person
{
    protected:
        double salary;
        int employment_date;
    public:
        Employee(std::string fname, std::string lname, int year, double sal, int date);
        ~Employee(){};
        virtual void print() const;
        double get_salary() const;
        void set_salary(double sal);
};

class Manager: public Employee
{
    protected:
        double com;
    public:
        Manager(std::string fname, std::string lname, int year, double sal, int date, double c);
        ~Manager(){};
        virtual void print() const;
        void set_com(double c);
        double get_com() const;
};

class Clerk: public Employee
{
    protected:
        Manager *m;
    public:
        Clerk(std::string fname, std::string lname, int year, double sal, int date, Manager *man);
        ~Clerk(){};
        virtual void print() const;
        void set(const Manager* man);
};