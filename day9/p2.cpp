#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

#define ll long long

ll solve(vector<ll> fs, vector<ll> lengths)
{
    int right = fs.size() - 1;
    while (right > 0)
    {
        int left = 1;
        int length_left = 1;
        while (left < right)
        {
            if (fs[left] == -1)
            {
                length_left = 1;
                while (left + length_left < fs.size() && fs[left + length_left] == -1)
                {
                    ++length_left;
                }
                if (length_left >= lengths[fs[right]])
                {
                    break;
                }
            }
            ++left;
        }

        if (left < right)
        {
            int first = fs[right];
            for (int i = 0; i < lengths[first]; ++i)
            {
                fs[left] = first;
                fs[right] = -1;
                --right;
                ++left;
            }
        }
        else
        {
            --right;
        }

        while (fs[right] == -1)
        {
            --right;
        }
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
    vector<ll> lengths;
    for (ll i = 0; i < data.size(); ++i)
    {
        int d = data[i] - '0';
        for (int j = 0; j < d; ++j)
        {
            fs.push_back(i % 2 == 0 ? i / 2 : -1);
        }
        if (i % 2 == 0)
            lengths.push_back(d);
    }
    cout << solve(fs, lengths) << endl;
    return 0;
}