#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> v;
    int q;
    cin >> q;
    while (q--)
    {
        int pos, val;
        cin >> pos >> val;
        if (pos == 0)
        {
            v.push_front(val);
        }

        else if (pos == 1)
        {
            v.push_back(val);
        }
        else if (pos == 2)
        {
            if (val < v.size())
            {
                v.erase(next(v.begin(), val));
            }
        }

        cout << "L -> ";
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;
        list<int> v2(v);
        v2.reverse();
        cout << "R -> ";
        for (int x : v2)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}