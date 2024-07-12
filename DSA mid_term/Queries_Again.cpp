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
void print_normal(Node *head)
{
    Node *tmp = head;
    cout << "L -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void print_reverse(Node *tail)
{
    Node *temp = tail;
    cout << "R -> ";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
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
void insert_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (tail == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (tail == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = tail->next;
}
void insert_at_position(Node *&head, int pos, int val)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    } // now temp in pos-1
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next->prev = newnode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int q;
    cin >> q;
    while (q--)
    {
        int pos, val;
        cin >> pos >> val;
        if (pos > size_linklist(head))
        {
            cout << "Invalid" << endl;
        }
        else if (pos == 0)
        {
            insert_head(head, tail, val);
            print_normal(head);
            print_reverse(tail);
        }
        else if (pos == size_linklist(head))
        {
            insert_tail(head, tail, val);
            print_normal(head);
            print_reverse(tail);
        }
        else
        {
            insert_at_position(head, pos, val);
            print_normal(head);
            print_reverse(tail);
        }
    }

    return 0;
}