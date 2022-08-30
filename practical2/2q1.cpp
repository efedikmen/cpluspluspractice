#include <iostream>

/*
    Problem 1:
    Declare int variables x and y and int* pointer variables p and q. 
    Set x to 2, y to 8, p to the address of x, and q to the address of y.
    Print:
*/

int main()
{
    int x,y,*p, *q;
    x = 2;
    y = 8;
    p = &x;
    q = &y;

    std::cout << "The address of x:" << &x << "and the value of x:" << x << std::endl;
    std::cout << "The value of p:" << p << "and the value of ∗p:" << *p << std::endl;
    std::cout << "The address of y:" << &y << "and the value of y:" << y << std::endl;
    std::cout << "The value of q:" << q << "and the value of ∗q:" << *q << std::endl;
    std::cout << "The address of p:" << &p << std::endl;
    std::cout << "The value of q:" << &q << std::endl;

    return 0;
}