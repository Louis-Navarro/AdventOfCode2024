#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int uniqueAntinodes(vector<string> v, unordered_map<char, vector<pair<int, int>>> pos)
{
    int n = v.size();
    int m = v[0].size();
    set<pair<int, int>> anti;

    for (auto cp : pos)
    {
        vector<pair<int, int>> ps = cp.second;
        for (int i = 0; i < ps.size(); ++i)
        {
            for (int j = i + 1; j < ps.size(); ++j)
            {
                int x1 = ps[i].first;
                int y1 = ps[i].second;
                int x2 = ps[j].first;
                int y2 = ps[j].second;

                int dx = x2 - x1;
                int dy = y2 - y1;

                int x = x2;
                int y = y2;

                while (x >= 0 && x < n && y >= 0 && y < m)
                {
                    anti.insert({x, y});
                    x += dx;
                    y += dy;
                }

                x = x1;
                y = y1;

                while (x >= 0 && x < n && y >= 0 && y < m)
                {
                    anti.insert({x, y});
                    x -= dx;
                    y -= dy;
                }
            }
        }
    }

    return anti.size();
}

int main()
{
    vector<string> v;
    unordered_map<char, vector<pair<int, int>>> pos;
    string s;

    while (cin >> s)
    {
        v.push_back(s);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '.')
            {
                pos[s[i]].push_back({v.size() - 1, i});
            }
        }
    }

    cout << uniqueAntinodes(v, pos) << endl;

    return 0;
}