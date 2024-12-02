#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

bool isSafeReport(const std::vector<int> &report)
{
    bool isIncreasing = true, isDecreasing = true;

    // Check if the sequence is either increasing or decreasing
    for (size_t i = 1; i < report.size(); ++i)
    {
        int diff = report[i] - report[i - 1];

        // Check if the difference is between 1 and 3
        if (std::abs(diff) < 1 || std::abs(diff) > 3)
        {
            return false; // Unsafe if difference is out of the valid range
        }

        if (diff > 0)
        {
            isDecreasing = false; // The sequence is not decreasing
        }
        if (diff < 0)
        {
            isIncreasing = false; // The sequence is not increasing
        }
    }

    // Report is safe if it's either strictly increasing or strictly decreasing
    return isIncreasing || isDecreasing;
}

int main()
{
    std::ifstream infile("input.txt");
    std::string line;
    int safeReportCount = 0;

    while (std::getline(infile, line))
    {
        std::vector<int> report;
        std::string temp;

        // Parse the current line into integers
        std::istringstream iss(line);
        while (iss >> temp)
        {
            report.push_back(std::stoi(temp));
        }

        // Check if the report is safe
        if (isSafeReport(report))
        {
            safeReportCount++;
        }
    }

    std::cout << "Total safe reports: " << safeReportCount << std::endl;
    return 0;
}
