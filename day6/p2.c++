#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

map<pair<int, int>, pair<int, int>> directions = {
    {{-1, 0}, {0, 1}},
    {{0, 1}, {1, 0}},
    {{1, 0}, {0, -1}},
    {{0, -1}, {-1, 0}}};

pair<int, int> newPos(vector<string> v, pair<int, int> p, pair<int, int> &d)
{
    while (v[p.first + d.first][p.second + d.second] == '#')
    {
        d = directions[d];
    }
    if (p.first + d.first >= 0 && p.first + d.first < v.size() && p.second + d.second >= 0 && p.second + d.second < v[0].size())
    {
        return {p.first + d.first, p.second + d.second};
    }
    return p;
}

int checkLoop(vector<string> v, pair<int, int> p)
{
    pair<int, int> slow = p;
    pair<int, int> fast = p;
    pair<int, int> slowDir = {-1, 0};
    pair<int, int> fastDir = {-1, 0};
    do
    {
        slow = newPos(v, slow, slowDir);
        pair<int, int> intFast = newPos(v, fast, fastDir);
        fast = newPos(v, intFast, fastDir);

        if (intFast == fast)
            return false;

    } while (!(slow == fast && slowDir == fastDir));

    return true;
}

int main()
{
    vector<string> v;
    string line;
    int i = 0, j = -1;
    cout << "Reading" << endl;
    while (cin >> line)
    {
        if (line.find("^") != string::npos)
        {
            j = line.find("^");
        }
        v.push_back(line);
        getline(cin, line);
        i += j == -1;
    }

    cout << "Checking" << endl;

    int total = 0;
    for (int x = 0; x < v.size(); x++)
    {
        cout << "Row " << x << endl;
        for (int y = 0; y < v[0].size(); y++)
        {
            if (x == i && y == j)
                continue;
            char old = v[x][y];
            v[x][y] = '#';
            total += checkLoop(v, pair<int, int>{i, j});
            v[x][y] = old;
        }
    }

    cout << total << endl;

    return 0;
}