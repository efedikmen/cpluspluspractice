#include <iostream>

int main()
{
    /* 
    Problem 3: Write a program that reads in a character char from the keyboard and then displays one of the following messages

    • If <char> is a lower case letter, the message ”The upper case character corresponding to <char> is ...”
    • If <char> is an upper case letter, the message ”The lower case character corresponding to <char> is ...”
    • If <char> is not a letter, the message ”<char> is not a letter”

    */

    char entry;

    std::cin >> entry;

    int num = int(entry);

    if (num > 64 && num < 91)
    {
        std::cout << "The lower case character corresponding to " << entry << " is " << char(num + 32)<< std::endl;
    }
    else if (num > 64+32 && num < 91+32)
    {
        std::cout << "The upper case character corresponding to " << entry << " is " << char(num - 32)<< std::endl;
    }
    else 
    {
        std::cout << "The message " << entry << " is not a character." << std::endl;
    }

    return 0;
}