#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int main() 
{
    std::ifstream input("../input.txt");

    if (!input)
    {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << input.rdbuf();
    std::string multiplier = buffer.str();

    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    std::smatch matches;
    std::string::const_iterator searchStart(multiplier.cbegin());
    
    int total = 0;
    
    while (std::regex_search(searchStart, multiplier.cend(), matches, pattern))
    {
        int first = std::stoi(matches[1].str());
        int second = std::stoi(matches[2].str());
        total += first * second;
        searchStart = matches.suffix().first;
    }

    input.close();

    std::cout << "Total: " << total << std::endl;

    return 0;
}