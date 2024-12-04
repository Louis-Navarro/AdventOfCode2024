#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int findWords(vector<string> grid)
{
    int n = grid.size(), m = grid[0].size();
    int total = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (grid[i][j] == 'A')
            {
                bool diagDown1 = grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S';
                bool diagDown2 = grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M';

                bool diagUp1 = grid[i + 1][j - 1] == 'M' && grid[i - 1][j + 1] == 'S';
                bool diagUp2 = grid[i + 1][j - 1] == 'S' && grid[i - 1][j + 1] == 'M';

                total += (diagDown1 || diagDown2) && (diagUp1 || diagUp2);
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