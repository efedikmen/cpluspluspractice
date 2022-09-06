#include <iostream>
#include "Shape.h"

int main()
{
    
    Point p(0,0);
    Point p1(0,3);
    Point p2(4,0);
    std::cout << p1.distance(p) << std::endl;
    std::cout << p.distance(p) << std::endl;
    std::cout << p.get_y() << std::endl;

    Triangle t(p, p1, p2);
    t.print();

    Rectangle rec;
    rec.print();

    Rectangle rec1(p2, 3.0, 5.0);
    rec1.print();

    Circle c;
    c.print();
    Circle c1(p1, 1);
    c1.print();

    Square s1;
    s1.print();
    Square s2(p2, 4);
    s2.print();

    return 0;
}