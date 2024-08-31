#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        if (a.first < b.first)
        {
            return true;
        }
        else if (a.first == b.first)
        {
            if (a.second > b.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }
    }
};
int main()
{
    int q;
    cin >> q;

    vector<pair<string, int>> v;
    while (q--)
    {
        string s;
        int n;
        cin >> s >> n;
        pair<string, int> pa;
        pa.first = s;
        pa.second = n;
        v.push_back(pa);
    }
    sort(v.begin(), v.end(), cmp());
    for (int i = 0; i < v.size(); i++)
    {
        pair<string, int> result = v[i];

        cout << result.first << " " << result.second << endl;
    }

    return 0;
}