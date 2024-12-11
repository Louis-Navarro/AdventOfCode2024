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

#define ll long long

int solve(vector<ll> v)
{
    ll n = v.size();

    for (int _ = 0; _ < 25; ++_)
    {
        cout << _ << " " << n << endl;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] == 0)
            {
                ++v[i];
            }
            else if (to_string(v[i]).size() % 2 == 0)
            {
                // split into two half of digits
                string s = to_string(v[i]);
                int half = s.size() / 2;
                int a = stoll(s.substr(0, half));
                int b = stoll(s.substr(half));
                v[i] = a;
                v.insert(v.begin() + i + 1, b);
                ++n;
                ++i;
            }
            else
            {
                v[i] *= 2024;
            }
        }
    }

    return n;
}

int main()
{
    vector<ll> v;
    ll x;
    while (cin >> x)
    {
        v.push_back(x);
    }

    cout << solve(v) << endl;
    return 0;
}