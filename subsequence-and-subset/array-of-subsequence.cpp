#include <iostream>
#include <vector>
#include <string>

void printArray(const std::vector<std::string> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';
}

std::vector<std::string> subsequences(std::string ans, std::string str)
{
    if (!str.size())
    {
        std::vector<std::string> list = {};
        list.push_back(ans);
        return list;
    }

    char first = str[0];

    std::vector<std::string> left = subsequences(ans + first, str.substr(1));
    std::vector<std::string> right = subsequences(ans, str.substr(1));

    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main()
{
    std::string res = "", str = "abc";
    std::vector<std::string> ans = subsequences(res, str);
    printArray(ans);
    return 0;
}