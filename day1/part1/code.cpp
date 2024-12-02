#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    // Open the input file
    std::ifstream infile("input.txt");

    // Vectors to store the left and right lists
    std::vector<int> left_list, right_list;
    int left, right;

    // Read the input file and populate the lists
    while (infile >> left >> right)
    {
        left_list.push_back(left);
        right_list.push_back(right);
    }

    // Sort both lists
    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());

    // Calculate the total distance
    int total_distance = 0;
    for (size_t i = 0; i < left_list.size(); ++i)
    {
        total_distance += std::abs(left_list[i] - right_list[i]);
    }

    // Output the total distance
    std::cout << "Total distance: " << total_distance << std::endl;

    return 0;
}