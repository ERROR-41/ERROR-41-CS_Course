#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string val;
    Node *prev;
    Node *next;
    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, string val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = tail->next;
}

bool check_availability(Node *head, string vals)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->val == vals)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        string val;
        if (cin >> val && val == "end")
        {
            insert_at_tail(head, tail, val);
        }
    }

    int q;
    cin >> q;
    Node *current = head;
    while (q--)
    {
        string st;
        cin >> st;
        if (st == "visit")
        {
            string s2;
            cin >> s2;
            if (check_availability(head, s2))
            {
                Node *temp = head;
                while (temp->val != s2)
                {
                    temp = temp->next;
                }
                current = temp;
                cout << current->val;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (st == "prev")
        {
            if (current->prev != NULL)
            {
                current = current->prev;
                cout << current->val << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (st == "next")
        {
            if (current->next != NULL)
            {
                current = current->next;
                cout << current->val << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
