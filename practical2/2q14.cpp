#include <iostream>

// Quick sort

void swap(double* a, double* b)
{
    if (a == b)
    {
        return;
    }
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(double nums[], int start, int end)
{
    // first picking the correct position for the pivot
    int count = 0;
    double pivot = nums[start];
    for (int i = start+1; i <= end; i++) 
    {
        (nums[i] < pivot) ? (count++) : (count += 0);
    }
    swap(&nums[start + count], &nums[start]);
    int j = start;
    int k = end;
    while (j < start + count && k > start + count)
    {
        while (nums[j] < pivot)
        {
            j++;
        }
        while (nums[k] > pivot)
        {
            k--;
        }
        if (j < start + count && k > start + count)
        {
            swap(&nums[j++], &nums[k--]);
        }
    }
    return start + count;
}

void quicksort(double nums[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = partition(nums, start, end);

    quicksort(nums, start, pivot - 1);
    quicksort(nums, pivot + 1, end);
    return;
}

int main()
{
    double arr[] = {4.12,5.23,6.4,4.432,3.234,2.45,2.23,14.43,6.235,7.235,3.34};
    quicksort(arr, 0, 10);
    for (double a:arr)
    {
        std::cout << a << std::endl;
    }
    return 0;
}