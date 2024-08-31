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

int result = 0;
void count_node(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    count_node(root->left);
    count_node(root->right);
    result += 1;
}
int maxHeight(Node *root)
{

    if (root == NULL)
        return 0;
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);

    return max(l, r) + 1;
}
int main()
{
    Node *root = input_tree();
    count_node(root);
    int node_count = result;
    int max_h = maxHeight(root);
    int p = pow(2, max_h);
    if (node_count == pow(2, max_h) - 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}