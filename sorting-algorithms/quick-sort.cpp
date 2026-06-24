#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int> &arr, int left, int right)
{
    int mid = left + (right - left) / 2, i = left, j = right;
    int pivot = arr[mid];

    while (i < j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i >= j)
        {
            return j;
        }

        std::swap(arr[i], arr[j]);
        i++, j--;
    }

    return j;
}

void printArray(const std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}

void quickSort(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int p = partition(arr, left, right);

    quickSort(arr, left, p);
    quickSort(arr, p + 1, right);
}

int main()
{
    std::vector<int> nums = {8, 1, 0, 9, 4, 2, 9, 4, 1};
    quickSort(nums, 0, nums.size() - 1);
    printArray(nums);
    return 0;
}

/*
Time Complexity - O(N log N)
Space Complexity - O(log N)
*/