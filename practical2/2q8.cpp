#include <iostream>
#include <string>

/*
Write a function mystrlen to count the number of characters of a string, without the null-terminated character
*/

int mystrlen(std::string s)
{
    int i = 0;
    for (char a:s)
    {
        i++;
    }
    return i;
}

int main()
{
    std::string s = "lsdafjandois fjlakdjsjfla";
    std::cout << mystrlen(s) << std::endl;
    return 0;
}