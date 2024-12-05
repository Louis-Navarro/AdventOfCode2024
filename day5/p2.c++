#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool checkUpdate(vector<int> &update, unordered_map<int, unordered_set<int>> m)
{
    bool ans = false;
    for (int i = 0; i < update.size(); i++)
    {
        unordered_set<int> s = m[update[i]];
        for (int j = 0; j < i; j++)
        {
            if (s.find(update[j]) != s.end())
            {
                swap(update[i], update[j]);
                ans = true;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    unordered_map<int, unordered_set<int>> m;
    string line;
    getline(cin, line);
    while (line != "")
    {
        // Get the number before "|" and the number after "|"
        int a = stoi(line.substr(0, line.find("|")));
        int b = stoi(line.substr(line.find("|") + 1));
        m[a].insert(b);
        getline(cin, line);
    }

    int total = 0;
    while (cin >> line)
    {
        if (line == "done")
            break;
        // Make a vector from comma separated list
        vector<int> v;
        while (line.find(",") != string::npos)
        {
            v.push_back(stoi(line.substr(0, line.find(","))));
            line = line.substr(line.find(",") + 1);
        }
        // Add the last value
        v.push_back(stoi(line));
        if (checkUpdate(v, m))
        {
            while (checkUpdate(v, m))
            {
                continue;
            }
            total += v[v.size() / 2];
        }
    }

    cout << total << endl;

    return 0;
}
