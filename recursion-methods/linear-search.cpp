#include <iostream>
#include <vector>
using namespace std;

bool found(vector<int> &arr, int target, int index)
{
    if (index == arr.size())
    {
        return false;
    }

    return arr[index] == target || found(arr, target, index + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    cout << found(nums, 5, 0) << "\n"; 
    return 0;
}