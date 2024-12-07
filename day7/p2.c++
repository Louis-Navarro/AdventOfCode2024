#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int getPower10(int n)
{
    long ans = 1;
    while (n != 0)
    {
        ans *= 10;
        n /= 10;
    }
    return ans;
}

bool isPossible(long target, vector<long> nums)
{
    if (nums.size() == 1)
    {
        return target == nums[0];
    }
    long last = nums[nums.size() - 1];
    nums.pop_back();
    bool ans = false;
    ans |= target % last == 0 ? isPossible(target / last, nums) : false;
    ans |= target - last >= 0 ? isPossible(target - last, nums) : false;
    long p = getPower10(last);
    ans |= target % p == last ? isPossible(target / p, nums) : false;
    return ans;
}

int main()
{
    string line;
    getline(cin, line);
    long total = 0;
    while (line != "")
    {
        // Parse "190: 10 19 20" as a=190, b=[10, 19, 20]
        int colon = line.find(":");
        long a = stol(line.substr(0, colon));
        vector<long> b;
        int space = line.find(" ");
        while (space != -1)
        {
            int nextSpace = line.find(" ", space + 1);
            if (nextSpace == -1)
            {
                b.push_back(stol(line.substr(space + 1)));
            }
            else
            {
                b.push_back(stol(line.substr(space + 1, nextSpace - space - 1)));
            }
            space = nextSpace;
        }
        if (isPossible(a, b))
        {
            cout << a << " is possible" << endl;
            total += a;
        }
        getline(cin, line);
    }
    cout << total << endl;
    return 0;
}