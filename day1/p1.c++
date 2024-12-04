#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> listA(n);
    vector<int> listB(n);

    for (int i = 0; i < n; i++)
    {
        cin >> listA[i];
        cin >> listB[i];
    }

    sort(listA.begin(), listA.end());
    sort(listB.begin(), listB.end());

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int distance = abs(listA[i] - listB[i]);
        total += distance;
    }

    cout << total << endl;

    return 0;
}