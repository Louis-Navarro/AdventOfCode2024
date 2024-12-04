// #include <iostream>
// #include <vector>
// #include <string>
// #include <sstream>

// using namespace std;

// int check_safe(vector<vector<int>> reports)
// {
//     int total = 0;
//     int n = reports.size();

//     for (int i = 0; i < n; i++)
//     {
//         // Vector of [works if keep all previous (1/0), works if remove one before but not previous (1/0), works if remove previous (1/0), diff with previous, diff with 2 before]
//         vector<vector<int>> dp(reports[i].size(), vector<int>(5, 0));
//         dp[0][0] = 1;
//         dp[0][1] = 1;
//         dp[0][2] = 1;
//         dp[0][3] = 0;
//         dp[0][4] = 0;
//         for (int j = 1; j < reports[i].size(); j++)
//         {
//             dp[j][3] = reports[i][j] - reports[i][j - 1];
//             dp[j][4] = j == 1 ? 0 : reports[i][j] - reports[i][j - 2];

//             dp[j][0] = dp[j - 1][0] && abs(dp[j][3]) >= 1 && abs(dp[j][3]) <= 3 && dp[j][3] * dp[j - 1][3] >= 0;
//             dp[j][1] = 1;
//             dp[j][2] = 1;
//             if (j > 1)
//             {
//                 // dp[j][1] -> either remove 2 before or before that
//                 dp[j][1] = dp[j - 1][2] && abs(dp[j][3]) >= 1 && abs(dp[j][3]) <= 3 && dp[j][3] * dp[j - 1][4] >= 0;  // Remove 2 before
//                 dp[j][1] |= dp[j - 1][1] && abs(dp[j][3]) >= 1 && abs(dp[j][3]) <= 3 && dp[j][3] * dp[j - 1][3] >= 0; // Remove before that
//                 dp[j][2] = dp[j - 2][0] && abs(dp[j][4]) >= 1 && abs(dp[j][4]) <= 3 && dp[j][4] * dp[j - 2][3] >= 0;
//             }

//             total += dp[reports[i].size() - 1][0] || dp[reports[i].size() - 1][1] || dp[reports[i].size() - 1][2];
//             // total += dp[reports[i].size() - 1][0];
//         }
//     }
//     return total;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> reports(n, vector<int>());

//     string line;
//     getline(cin, line);

//     for (int i = 0; i < n; i++)
//     {
//         int c;
//         getline(cin, line);
//         istringstream iss(line);
//         while (iss >> c)
//         {
//             reports[i].push_back(c);
//         }
//     }

//     cout << check_safe(reports) << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int check_safe(vector<int> report)
{
    int total = 0;
    int n = report.size();

    bool safe = true;
    int lastDiff = 0;
    for (int j = 1; j < n; j++)
    {
        int diff = report[j] - report[j - 1];
        safe &= abs(diff) >= 1 && abs(diff) <= 3; // Within constraints
        safe &= diff * lastDiff >= 0;             // Same sign
        lastDiff = diff;
    }
    total += safe;

    return total;
}

int check_safe_with_error(vector<vector<int>> reports)
{
    int total = 0;

    for (int i = 0; i < reports.size(); i++)
    {
        vector<int> report = reports[i];
        if (check_safe(report))
        {
            ++total;
            continue;
        }
        for (int j = 0; j < report.size(); j++)
        {
            vector<int> new_report = report;
            new_report.erase(new_report.begin() + j);
            if (check_safe(new_report))
            {
                ++total;
                break;
            }
        }
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

    cout << check_safe_with_error(reports) << endl;

    return 0;
}