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
    set<pair<int, int>> s;
    pair<int, int> slow = p;
    pair<int, int> fast = p;
    pair<int, int> slowDir = {-1, 0};
    pair<int, int> fastDir = {-1, 0};
    do
    {
        s.insert(slow);
        s.insert(fast);
        slow = newPos(v, slow, slowDir);
        fast = newPos(v, fast, fastDir);
        fast = newPos(v, fast, fastDir);

    } while (!(slow == fast && slowDir == fastDir) && slow.first >= 0 && slow.first < v.size() && slow.second >= 0 && slow.second < v[0].size());

    return s.size();
}

int main()
{
    vector<string> v;
    string line;
    int i = 0, j = -1;
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

    cout << checkLoop(v, pair<int, int>{i, j}) << endl;

    return 0;
}