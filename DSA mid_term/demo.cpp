#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> v;
    string s;
    while (cin >> s && s != "end")
    {
        v.push_back(s);
    }

    int q;
    cin >> q;
    while (q--)
    {
        string s1;
        cin >> s1;
        if (s1 == "visit")
        {
            string s3;
            cin >> s3;
            auto it = find(v.begin(), v.end(), s3);
            if (it != v.end())
            {
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (s1 == "pre")
        {
        }
        else if (s1 == "next")
        {
        }
    }

    return 0;
}