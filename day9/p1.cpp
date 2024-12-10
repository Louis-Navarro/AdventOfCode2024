#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ll unsigned long long

ll solve(vector<ll> fs)
{
    int left = 0;
    int right = fs.size() - 1;
    while (right >= left)
    {
        if (fs[left] == -1)
        {
            swap(fs[left], fs[right]);
            while (fs[right] == -1)
            {
                --right;
            }
        }
        ++left;
    }

    ll total = 0;
    for (ll i = 0; i < fs.size(); ++i)
    {
        if (fs[i] != -1)
        {
            total += i * fs[i];
        }
    }
    return total;
}

int main()
{
    string data;
    cin >> data;
    vector<ll> fs;
    for (ll i = 0; i < data.size(); ++i)
    {
        int d = data[i] - '0';
        for (int j = 0; j < d; ++j)
        {
            fs.push_back(i % 2 == 0 ? i / 2 : -1);
        }
    }
    cout << solve(fs) << endl;
    return 0;
}