#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int r;
        cin >> r;
        list<int> l;
        while (r--)
        {
            int data;
            cin >> data;
            l.push_back(data);
        }

        l.sort();
        l.unique();

        for (int x : l)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}