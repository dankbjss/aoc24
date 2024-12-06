#include <iostream>
#include <sstream>

#include "helpers.h"

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

bool problemDampener(std::vector<int> report)
{
    for (int i = 0; i < (int)report.size(); i++)
    {
        std::vector<int> reportCopy = report;
        reportCopy.erase(reportCopy.begin() + i);
        Order order = reportCopy[0] < reportCopy[1] ? Order::ASCENDING : Order::DESCENDING;

        if (reportIsSafe(reportCopy, order))
        {
            return true;
        }
    }

    return false;
}

void printVector(std::vector<int> vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;
}