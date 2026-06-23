#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }

    cout << "\n";
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> leftTemp(leftSize), rightTemp(rightSize);

    for (int i = 0; i < leftSize; i++)
    {
        leftTemp[i] = arr[left + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightTemp[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;

    vector<int> temp;

    while (i < leftSize && j < rightSize)
    {
        if (leftTemp[i] <= rightTemp[j])
        {
            temp.push_back(leftTemp[i]);
            i++;
        }

        else
        {
            temp.push_back(rightTemp[j]);
            j++;
        }
    }

    while (i < leftTemp.size())
    {
        temp.push_back(leftTemp[i]);
        i++;
    }

    while (j < rightTemp.size())
    {
        temp.push_back(rightTemp[j]);
        j++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + left] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main()
{
    vector<int> nums = {8, 1, 0, 9, 4, 2, 9, 4, 1};
    mergeSort(nums, 0, nums.size() - 1);
    printArray(nums);
    return 0;
}

/*
Explaination for Time Complexity:-
* When a recursive call occurs, then the array will get divided into half each time.
* When there is only one element left the number can be shown as N / (2^k) where k is the number of levels.
* This can be shown by the equation 1 = N / (2 ^ k)
* After simplifying we get k = log N.
* These are N operations in a single level.
* Since there are a total of N levels in each recursive call, the total number of operations are N log N
* Hence the time complexity for the algorithm is O(N log N)
* Similar explanation for binary search but the difference is that the TC will be O(log N) since the N elements aren't being compared in each level.

-----------------#####################################---------------------------------------

Explanation for Space Complexity:-
* A stack element will be added to call stack once a level is completed.
* Hence for k levels, the space complexity will be O(log N).
* But we are also creating left, right and temp arrays.
* The left and right will store N elements collectively and temp will store N elements. 
* Hence this will take N auxilliary space.
* Since O(N) grows significantly faster than O(log N), the space complexity will be O(N).
* Similar explanation for binary search through recursion.
*/