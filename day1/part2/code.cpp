#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main()
{
    std::ifstream infile("input.txt");

    std::vector<int> left_list, right_list;
    int left, right;

    while (infile >> left >> right)
    {
        left_list.push_back(left);
        right_list.push_back(right);
    }

    // Create a frequency map for the right list
    std::unordered_map<int, int> right_freq;
    for (int num : right_list)
    {
        right_freq[num]++;
    }

    // Calculate the similarity score
    int similarity_score = 0;
    for (int num : left_list)
    {
        similarity_score += num * right_freq[num];
    }

    // Output the similarity score
    std::cout << "Total similarity score: " << similarity_score << std::endl;

    return 0;
}
