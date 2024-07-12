#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;

        stack<int> st;
        for (char x : s)
        {
            int n = x - 48;
            if (!st.empty())
            {
                int top = st.top();
                if (top == 1 && n == 0)
                {
                    if (!st.empty())
                    {
                        st.pop();
                    }
                }
                else if (top == 0 && n == 1)
                {
                    if (!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.push(n);
                }
            }
            else
            {
                st.push(n);
            }
        }
        if (!st.empty())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}