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

#define ll unsigned long long

ll solve(unordered_map<ll, ll> v)
{
    ll n = 0;

    for (int _ = 0; _ < 75; ++_)
    {
        // cout << "Iteration " << _ << " size " << v.size() << endl;
        n = 0;
        unordered_map<ll, ll> v2;
        for (auto &p : v)
        {
            if (p.first < 0)
            {
                throw "Fuck, negative number";
            }
            else if (p.first == 0)
            {
                v2[1] += p.second;
            }
            else if (to_string(p.first).size() % 2 == 0)
            {
                // split into two half of digits
                string s = to_string(p.first);
                int half = s.size() / 2;
                int a = stoll(s.substr(0, half));
                int b = stoll(s.substr(half));
                v2[a] += p.second;
                v2[b] += p.second;
                n += p.second;
            }
            else
            {
                v2[p.first * 2024] += p.second;
            }
            n += p.second;
        }
        v = v2;
    }

    return n;
}

int main()
{
    unordered_map<ll, ll> v;
    ll x;
    while (cin >> x)
    {
        ++v[x];
    }

    cout << solve(v) << endl;
    return 0;
}