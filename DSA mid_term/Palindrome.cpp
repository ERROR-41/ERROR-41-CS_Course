#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
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

void print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

int size_linklist(Node *head)
{
    int count = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}
void ispalindrome(Node *i, Node *j)
{
    bool flag = true;
    while (i != j && i->next != j)
    {
        if (i->val == j->val)
        {
            swap(i->val, j->val);
        }
        else
        {
            flag = false;
            break;
        }
        i = i->next;
        j = j->prev;
    }
    if (flag == true)
    {
        if (i->val == j->val)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    if (flag == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    ispalindrome(head, tail);
    return 0;
}