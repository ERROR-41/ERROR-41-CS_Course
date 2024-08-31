#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};
class cmp
{
public:
    bool operator()(Student s1, Student s2)
    {
        if (s1.marks == s2.marks)
        {
            if (s1.roll > s2.roll)
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
            if (s1.marks < s2.marks)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student s(name, roll, marks);
        pq.push(s);
    }
    int h;
    cin >> h;
    while (h--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student r(name, roll, marks);
            pq.push(r);
            Student e = pq.top();
            cout << e.name << " " << e.roll << " " << e.marks << endl;
        }
        else if (x == 1)
        {
            if (!pq.empty())
            {
                Student e = pq.top();
                cout << e.name << " " << e.roll << " " << e.marks << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (x == 2)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                pq.pop();
                if (!pq.empty())
                {
                    Student e = pq.top();
                    cout << e.name << " " << e.roll << " " << e.marks << endl;
                }
                else
                {
                    cout << "Empty" << endl;
                }
            }
        }
    }
    return 0;
}