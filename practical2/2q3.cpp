#include <iostream>

// Problem 3

// Version 1: f is an integer reference, adds 5 to the value of the int it is used on
int & f(int & a)
{   
    a=a+5;
    return a;
}


// Version 2: f is a function therefore incrementing it below gives an error
/*
int f(int & a)
{   
    a=a+5;
    return a;
}
*/

// Version 3: f(a) is an integer that is 5 more of a, but doesn't affect a's value
/*
int & f(int a)
{   
    a=a+5;
    return a;
}
*/

// Version 4: f is a function, therefore will cause an error when trying to increment it
/*
int f(int a)
{   
    a=a+5;
    return a;
}
*/

int main(){
    int a=5;
    for (int i=0;i<2;i++)
    { 
        f(a)++;
    }
    std::cout << f(a);
    return 0;
}