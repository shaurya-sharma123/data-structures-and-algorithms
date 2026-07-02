#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> subsequencesDuplicates(const std::vector<int> &arr)
{
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> outer = {{}};
    int start = 0, end = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        start = 0;

        if (i > 0 && (arr[i] == arr[i - 1]))
        {
            start = end + 1;
        }

        end = outer.size() - 1;
        int n = outer.size();

        for (int j = start; j < n; j++) 
        {
            std::vector<int> inner = outer[j];
            inner.push_back(arr[i]);
            outer.push_back(inner);
        }
    }

    return outer;
}

int main()
{
    std::vector<int> arr = {1, 2, 2, 3};
    std::vector<std::vector<int>> res = subsequencesDuplicates(arr);
    return 0;
}