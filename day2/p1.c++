#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int check_safe(vector<vector<int>> reports)
{
    int total = 0;
    int n = reports.size();

    for (int i = 0; i < n; i++)
    {
        bool safe = true;
        int lastDiff = 0;
        for (int j = 1; j < reports[i].size(); j++)
        {
            int diff = reports[i][j] - reports[i][j - 1];
            safe &= abs(diff) >= 1 && abs(diff) <= 3; // Within constraints
            safe &= diff * lastDiff >= 0;             // Same sign
            lastDiff = diff;
        }
        total += safe;
    }

    return total;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> reports(n, vector<int>());

    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++)
    {
        int c;
        getline(cin, line);
        istringstream iss(line);
        while (iss >> c)
        {
            reports[i].push_back(c);
        }
    }

    cout << check_safe(reports) << endl;

    return 0;
}