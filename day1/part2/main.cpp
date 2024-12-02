#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> left;
    std::vector<int> right;
    int leftNumber, rightNumber;
    std::ifstream input;
    int similarity = 0;

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

    for (int number : left)
    {
        int count = std::count(right.begin(), right.end(), number);
        if (count > 0)
        {
            similarity += count * number;
        }
    }

    std::cout << similarity << std::endl;

    return 0;
}