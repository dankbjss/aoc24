#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

enum class Order
{
    ASCENDING,
    DESCENDING
};

std::vector<int> readReport(std::string line);
bool reportIsSafe(std::vector<int> report, Order order);

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
            safeCount++;
        }
    }

    std::cout << safeCount << std::endl;

    return 0;
}

std::vector<int> readReport(std::string line)
{
    std::vector<int> report;
    std::istringstream iss(line);
    int number;

    while (iss >> number)
    {
        report.push_back(number);
    }

    return report;
}

bool reportIsSafe(std::vector<int> report, Order order)
{
    for (int i = 0; i < (int)report.size() - 1; i++)
    {
        if (report[i] == report[i + 1])
        {
            return false;
        }

        if (order == Order::ASCENDING)
        {
            if (report[i] > report[i + 1])
            {
                return false;
            }
        }
        else
        {
            if (report[i] < report[i + 1])
            {
                return false;
            }
        }

        int difference = std::abs(report[i] - report[i + 1]);
        if (difference > 3)
        {
            return false;
        }
    }

    return true;
}