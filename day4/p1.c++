#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

unordered_map<char, char> order{
    {'X', 'M'},
    {'M', 'A'},
    {'A', 'S'},
    {'S', 'X'},
};

int dfs(vector<string> grid, int i, int j, int x, int y)
{
    if (grid[i][j] == 'S')
        return 1;
    int n = grid.size(), m = grid[0].size();
    char next = order[grid[i][j]];

    int total = 0;
    int ni = i + x, nj = j + y;
    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == next)
    {
        total += dfs(grid, ni, nj, x, y);
    }
    return total;
}

int findWords(vector<string> grid)
{
    int n = grid.size(), m = grid[0].size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                        continue;
                    total += grid[i][j] == 'X' ? dfs(grid, i, j, x, y) : 0;
                }
            }
        }
    }

    return total;
}

int main()
{
    int n;
    cin >> n;

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        grid[i] = line;
    }

    cout << findWords(grid) << endl;

    return 0;
}