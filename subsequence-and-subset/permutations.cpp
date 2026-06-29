#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> permutations(std::string left, std::string right)
{
    if (right.empty())
    {
        std::vector<std::string> list;
        list.push_back(left);
        return list;
    }

    std::vector<std::string> ans = {};
    char ch = right[0];

    for (int i = 0; i <= left.size(); i++)
    {
        std::string first = left.substr(0, i), second = left.substr(i, left.size());
        std::vector<std::string> callFromBelow = permutations(first + ch + second, right.substr(1));
        ans.insert(ans.end(), callFromBelow.begin(), callFromBelow.end());
    }

    return ans;
}

int main()
{
    std::string right = "abc";
    std::vector<std::string> resArr = permutations("", right);

    for (int i = 0; i < resArr.size(); i++)
    {
        std::cout << resArr[i] << " ";
    }

    return 0;
}