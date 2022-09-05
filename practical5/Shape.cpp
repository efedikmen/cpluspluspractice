#include <iostream>
#include <cmath>
#include "Shape.h"

// functions for point
Point::Point()
{
    x = 0;
    y = 0;
};
Point::Point(double x1, double y1)
{
    x = x1;
    y = y1;
};
double Point::get_x() const
{ return x; };
double Point::get_y() const
{ return y; };
void Point::set_x(double a)
{ x = a; };
void Point::set_y(double a)
{ y = a; };
void Point::set_all(double a, double b)
{
    set_x(a);
    set_y(b);
}
double Point::distance(const Point & p) const
{ return sqrt(pow(x-p.x, 2)+pow(y-p.y, 2)); };
Point & Point::operator= (const Point &p)
{
    set_all(p.x, p.y);
    return *this;
};

// functions for triangle
Triangle::Triangle()
{};
Triangle::Triangle(const Point & pa, const Point & pb, const Point & pc)
{
    if (!CheckIfTriangle(pa, pb, pc)) exit(1);
    p1 = pa;
    p2 = pb;
    p3 = pc;
};
double Triangle::side1() const
{
    return p1.distance(p2);
};
double Triangle::side2() const
{
    return p2.distance(p3);
};
double Triangle::side3() const
{
    return p3.distance(p1);
};
double Triangle::area() const
{
    // Using Heron's formula to calculate the area of the triangle
    double a = side1(), b = side2(), c = side3();
    double s = perimeter()/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
};
double Triangle::perimeter() const
{
    return side1()+side2()+side3();
};
void Triangle::SetPoints(const Point & pa, const Point & pb, const Point & pc)
{
    p1 = pa;
    p2 = pb;
    p3 = pc;
};
void Triangle::print() const
{

    std::cout << "Point 1 coordinates: " << p1.get_x() << ',' << p1.get_y() << std::endl;
    std::cout << "Point 2 coordinates: " << p2.get_x() << ',' << p2.get_y() << std::endl;
    std::cout << "Point 3 coordinates: " << p3.get_x() << ',' << p3.get_y() << std::endl;
    std::cout << "Side 1 length: " << side1() << std::endl;
    std::cout << "Side 2 length: " << side2() << std::endl;
    std::cout << "Side 3 length: " << side3() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
    std::cout << "Area: " << area() << std::endl;
};

//functions for rectangle
Rectangle::Rectangle()
{
    w = 0.0;
    h = 0.0;
};
Rectangle::Rectangle(Point & pt, double height, double width)
{
    p = pt;
    h = height;
    w = width;
};
double Rectangle::area() const
{
    return w*h;
};
double Rectangle::perimeter() const
{
    return 2*h+2*w;
};
void Rectangle::set_width(double width)
{
    w = width;
};
void Rectangle::set_height(double height)
{
    h = height;
};
void Rectangle::set_point(Point & pt)
{
    p.set_x(pt.get_x());
    p.set_y(pt.get_y());
};
double Rectangle::get_width() const
{
    return w;
};
double Rectangle::get_height() const
{
    return h;
};
void Rectangle::print() const
{
    std::cout << "Height of the rectangle: " << get_height() << std::endl;
    std::cout << "Width of the rectangle: " << get_width() << std::endl;
    std::cout << "Coordinates of the left bottom point of the rectangle: " << p.get_x() << ',' << p.get_y() << std::endl;
    std::cout << "Perimeter of the rectangle: " << perimeter() << std::endl;
    std::cout << "Area of the rectangle: " << area() << std::endl;
};

//functions for circle
Circle::Circle()
{
    r = 0;
};
Circle::Circle(Point & pt, double radius)
{
    p = pt;
    r = radius;
};
double Circle::area() const
{
    return M_PI * r * r;
};
double Circle::perimeter() const
{
    return M_PI * 2 * r;
};
void Circle::print() const
{
    std::cout << "Coordinates of the circle's center: " << p.get_x() << ',' << p.get_y() << std::endl;
    std::cout << "Radius of the circle: " << r << std::endl;
    std::cout << "Area of the circle: " << area() << std::endl;
    std::cout << "Perimeter of the circle: " << perimeter() << std::endl;
};
 
//functions for square

Square::Square()
{
    rec.set_height(1);
    rec.set_width(1);
};
Square::Square(const Point & pt, double size)
{
    Point p(pt.get_x(), pt.get_y());
    rec.set_point(p);
    rec.set_height(size);
    rec.set_width(size);
}
double Square::area() const
{ return rec.area(); };
double Square::perimeter() const
{ return rec.perimeter(); };
void Square::print() const
{
    std::cout << "Side length of the square: " << rec.get_height() << std::endl;
    std::cout << "Area of the square: " << area() << std::endl;
    std::cout << "Perimeter of the square: " << perimeter() << std::endl;
}
