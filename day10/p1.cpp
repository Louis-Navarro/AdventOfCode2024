#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

set<pair<int, int>> dfs(vector<vector<int>> heights, int x, int y)
{
    if (heights[x][y] == 9)
    {
        return {{x, y}};
    }

    set<pair<int, int>> seen;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if ((i == 0 && j == 0) || (i * j != 0))
            {
                continue;
            }
            if (x + i >= 0 && x + i < heights.size() && y + j >= 0 && y + j < heights[0].size() && heights[x + i][y + j] == heights[x][y] + 1)
            {
                set<pair<int, int>> temp = dfs(heights, x + i, y + j);
                seen.insert(temp.begin(), temp.end());
            }
        }
    }
    return seen;
}

int solve(vector<vector<int>> heights)
{
    int total = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        for (int j = 0; j < heights[0].size(); j++)
        {
            if (heights[i][j] == 0)
            {
                set<pair<int, int>> temp = dfs(heights, i, j);
                total += temp.size();
            }
        }
    }
    return total;
}

int main()
{
    vector<vector<int>> heights;
    string line;

    while (cin >> line)
    {
        vector<int> cur;
        for (int i = 0; i < line.size(); i++)
        {
            cur.push_back(line[i] - '0');
        }
        heights.push_back(cur);
    }

    cout << solve(heights) << endl;

    return 0;
}