#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    queue<string> qu;

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            string name;
            cin >> name;
            qu.push(name);
        }
        else if (op == 1)
        {
            if (!qu.empty())
            {
                cout << qu.front() << endl;
                qu.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }
    return 0;
}