#include <iostream>
#include <fstream>
#include <sstream>

#include "helpers.h"

int main()
{
    std::ifstream input("../input.txt");

    if (!input)
    {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    int safeCount = 0;

    std::string line;

    while (std::getline(input, line))
    {
        std::vector<int> report = readReport(line);
        Order order = report[0] < report[1] ? Order::ASCENDING : Order::DESCENDING;

        if (reportIsSafe(report, order))
        {
            std::cout << "Safe: ";
            printVector(report);

            safeCount++;
        }
        else
        {
            if (problemDampener(report))
            {
                std::cout << "Safe: ";
                printVector(report);

                safeCount++;
            }
            else
            {
                std::cout << "Unsafe: ";
                printVector(report);
            }
        }
    }

    std::cout << "Safe Reports: " << safeCount << std::endl;

    return 0;
}