#pragma once
#include <iostream>

// a class hierarchy for shapes

class Shape
{
    public:
        virtual void print() const=0;
        virtual double area() const=0;
        virtual double perimeter() const=0;
        virtual ~Shape(){};
};

class Point
{
    protected:
        double x;
        double y;
    public:
        Point();
        Point(double x1, double y1);
        ~Point(){};
        double get_x() const;
        double get_y() const;
        void set_x(double a);
        void set_y(double a);
        void set_all(double a, double b);
        double distance(const Point & p) const;
        Point & operator= (const Point &p);
};

class Triangle: public Shape
{
    private:
        Point p1, p2, p3;
        bool CheckIfTriangle(const Point & p1, const Point & p2, const Point & p3)
        {
            if (p1.get_x() == p2.get_x() && p1.get_x() == p3.get_x())
            {
                return false;
            }
            if (p1.get_y() == p2.get_y() && p1.get_y() == p3.get_y())
            {
                return false;
            }
            return true;
        }
    public:
        Triangle();
        Triangle(const Point & pa, const Point & pb, const Point & pc);
        ~Triangle(){};
        void print() const;
        double area() const;
        double perimeter() const;
        void SetPoints(const Point & pa, const Point & pb, const Point & pc);
        double side1() const;
        double side2() const;
        double side3() const;
};

class Rectangle: public Shape
{
    private:
        Point p;
        double h;
        double w;
    public:
        Rectangle();
        Rectangle(Point & pt, double height, double width);
        ~Rectangle(){};
        void print() const;
        double area() const;
        double perimeter() const;
        void set_width(double width);
        void set_height(double height);
        double get_width() const;
        double get_height() const;
        void set_point(Point & pt);
};

class Circle: public Shape
{
    private:
        Point p;
        double r;
    public:
        Circle();
        Circle(Point & pt, double radius);
        ~Circle(){};
        void print() const;
        double area() const;
        double perimeter() const;
};

class Square: public Shape
{
    private:
        Rectangle rec;
    public:
        Square();
        Square(const Point & p, double s);
        ~Square() {};
        void set_size(double size);
        void print() const;
        double area() const;
        double perimeter() const;
};