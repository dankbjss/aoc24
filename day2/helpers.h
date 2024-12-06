#ifndef HELPERS_H
#define HELPERS_H

#include <vector>

enum class Order
{
    ASCENDING,
    DESCENDING
};

std::vector<int> readReport(std::string line);

bool reportIsSafe(std::vector<int> report, Order order);

bool problemDampener(std::vector<int> report);

void printVector(std::vector<int> vec);

#endif