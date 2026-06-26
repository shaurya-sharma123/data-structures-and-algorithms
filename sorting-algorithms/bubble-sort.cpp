#include <iostream>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';
}

void bubbleSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 1; i < arr.size() - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> nums = {5, 4, 3, 2, 1};
    bubbleSort(nums);
    printArray(nums);
    return 0;
}