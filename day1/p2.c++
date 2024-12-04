#include <iostream>
#include <vector>
#include <string>

using namespace std;

void similarity(vector<int> listA, vector<int> listB)
{
    int n = listA.size();

    unordered_map<int, int> countB(0);
    for (int i = 0; i < n; i++)
    {
        countB[listB[i]]++;
    }

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += listA[i] * countB[listA[i]];
    }

    cout << total << endl;
}

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

    similarity(listA, listB);

    return 0;
}