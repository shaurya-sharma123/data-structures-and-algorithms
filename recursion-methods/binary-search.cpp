#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int binarySearch(vector<int> &arr, int target, int left, int right)
    {

        if (left > right)
        {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (target > arr[mid])
        {
            return binarySearch(arr, target, mid + 1, right);
        }

        else if (target < arr[mid])
        {
            return binarySearch(arr, target, left, mid - 1);
        }

        return mid;
    }

public:
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};

int main()
{
    Solution S;
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << S.search(arr, 4);
    return 0;
}