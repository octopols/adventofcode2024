#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool checkReport(const vector<int> &arr)
{
    int diff1 = 0;
    int diff2 = 0;
    bool val = true;

    for (size_t j = 0; j < arr.size() - 1; ++j)
    {
        diff2 = diff1;
        diff1 = arr[j] - arr[j + 1];

        if (diff1 < -3 || diff1 > 3)
        {
            val = false;
            break;
        }
        if (j != 0 && diff1 * diff2 <= 0)
        {
            val = false;
            break;
        }
    }

    return val;
}

bool dampen(vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        int tmp = arr[i];
        arr.erase(arr.begin() + i);
        bool dampen = checkReport(arr);
        arr.insert(arr.begin() + i, tmp);

        if (dampen)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    vector<vector<int>> arr;
    string line;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        vector<int> tmp;
        int num;

        while (ss >> num)
        {
            tmp.push_back(num);
        }

        arr.push_back(tmp);
    }

    inputFile.close();

    int res = 0;

    for (auto &subArr : arr)
    {
        bool val = checkReport(subArr);
        if (!val)
        {
            val = dampen(subArr);
        }
        if (val)
        {
            ++res;
        }
    }

    cout << "Number of Safe Reports" << res << endl;

    return 0;
}
