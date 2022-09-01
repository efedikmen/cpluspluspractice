#include <iostream>

/*
Write a sort algorithm of an array a[]
*/

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] > a[i])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}

int main()
{
    int test[7] = {7,1,2,3,4,5,6};
    sort(test, 7);
    for (int t:test)
    {
        std::cout << t << std::endl;
    }
    return 0;
}