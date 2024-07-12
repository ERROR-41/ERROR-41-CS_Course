#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> q;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    if (st.size() == q.size())
    {
        bool flag = false;
        while (!st.empty())
        {
            if (st.top() == q.front())
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
            st.pop();
            q.pop();
        }

        if (flag)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
