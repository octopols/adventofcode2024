// NOT WORKING ILL WORK ON IT TOMORROW

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

// Function to check if a report is safe without any removal
bool is_safe_report(const std::vector<int> &levels)
{
    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < levels.size(); ++i)
    {
        int diff = levels[i] - levels[i - 1];
        if (diff < 1 || diff > 3)
        {
            return false; // If difference is not between 1 and 3, report is unsafe
        }
        if (diff > 0)
            decreasing = false;
        if (diff < 0)
            increasing = false;
    }

    return increasing || decreasing; // Must be either all increasing or all decreasing
}

// Function to check if a report can be made safe by removing one level
bool is_safe_with_one_removal(std::vector<int> levels)
{
    for (size_t i = 0; i < levels.size(); ++i)
    {
        std::vector<int> modified_levels = levels;
        modified_levels.erase(modified_levels.begin() + i); // Remove one level
        if (is_safe_report(modified_levels))
        {
            return true; // If removing one level makes it safe, return true
        }
    }
    return false; // If no level can be removed to make it safe, return false
}

int main()
{
    std::ifstream input_file("input.txt"); // Open input file
    if (!input_file)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1; // Return an error code if file cannot be opened
    }

    std::string line;
    int safe_report_count = 0;

    // Read each line from the file
    while (std::getline(input_file, line))
    {
        std::vector<int> levels;
        std::istringstream iss(line);
        int level;

        // Read the levels from the current report
        while (iss >> level)
        {
            levels.push_back(level);
        }

        // Check if the report is safe without any removal
        if (is_safe_report(levels))
        {
            safe_report_count++;
        }
        // If not safe, check if removing one level makes it safe
        else if (is_safe_with_one_removal(levels))
        {
            safe_report_count++;
        }
    }

    std::cout << "Total safe reports: " << safe_report_count << std::endl;

    input_file.close(); // Close the file
    return 0;
}
