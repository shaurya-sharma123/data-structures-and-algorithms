#include <iostream>
#include <vector>

std::vector<std::vector<int>> arrayOfSubsequence(const std::vector<int> &arr)
{
    std::vector<std::vector<int>> outer = {};
    outer.push_back({});

    for (int num : arr)
    {
        int n = outer.size();

        for (int i = 0; i < n; i++)
        {
            std::vector<int> inner = outer[i];
            inner.push_back(num);
            outer.push_back(inner);
        }
    }

    return outer;
}

int main()
{
    std::vector<int> arr = {1, 2, 3};
    std::vector<std::vector<int>> v = arrayOfSubsequence(arr);
    return 0;
}

/*
    Time Complexity = O(N * 2^N)-
        N is the number of elements in each subset
        2^N is the number of subsets due to N elements

    Space Complexity = O(N * 2^N)
        N is the space taken by N elements
        2^N is the space taken my subsets

*/