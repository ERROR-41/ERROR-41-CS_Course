#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root = nullptr;
    }
    else
    {
        root = new Node(val);
    }

    queue<Node *> q;

    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {

        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myLeft;
        Node *myRight;

        if (l == -1)
        {
            myLeft = NULL;
        }
        else
        {
            myLeft = new Node(l);
        }

        if (r == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Node(r);
        }

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
    return root;
}
queue<int> l;
void print_left(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        print_left(root->left);
        l.push(root->left->val);
    }
    else if (root->right)
    {
        print_left(root->right);
        l.push(root->right->val);
    }
}
queue<int> r;
void print_right(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right)
    {
        r.push(root->right->val);
        print_right(root->right);
    }
    else if (root->left)
    {
        r.push(root->left->val);
        print_right(root->left);
    }
}

int main()
{
    Node *root = input_tree();
    print_left(root);
    print_right(root);
    if (root->left)
    {
        while (!l.empty())
        {
            cout << l.front() << " ";
            l.pop();
        }
    }

    cout << root->val << " ";
    if (root->right)
    {
        while (!r.empty())
        {
            cout << r.front() << " ";
            r.pop();
        }
    }

    return 0;
}