#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> left;
    std::vector<int> right;
    int leftNumber, rightNumber;
    std::ifstream input;
    std::vector<int> totals;

    input.open("../input.txt");

    if (!input)
    {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    while (input >> leftNumber >> rightNumber)
    {
        left.push_back(leftNumber);
        right.push_back(rightNumber);
    }

    input.close();

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    for (int i = 0; i < (int)left.size(); i++)
    {
        if (left[i] > right[i])
        {
            totals.push_back(left[i] - right[i]);
        }
        else
        {
            totals.push_back(right[i] - left[i]);
        }
    }

    int sum = std::accumulate(totals.begin(), totals.end(), 0);

    std::cout << sum << std::endl;

    return 0;
}
