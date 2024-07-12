#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> v;
    int x;

    while (cin >> x && x != -1)
    {
        v.push_back(x);
    }
    v.sort();
    v.unique();
    for (int k : v)
    {
        cout << k << " ";
    }

    return 0;
}