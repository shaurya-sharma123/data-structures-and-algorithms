#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &arr, int index)
{
    if (index >= arr.size() - 1)
    {
        return true;
    }

    return arr[index] <= arr[index + 1] && isSorted(arr, index + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 5, 4, 6, 7};

    if (isSorted(nums, 0))
    {
        cout << "The array is sorted!\n";
    }
    
    else
    {
        cout << "The array is NOT sorted.\n";
    }

    return 0;
}