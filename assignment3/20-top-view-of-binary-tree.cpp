// https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/

#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    int hd; // horizontal distance;

    Node(int val)
    {
        this->val = val;
        this->hd = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void topView(Node* root)
{
    if (root == nullptr)
        return;

    queue<Node*> q;
    map<int, int> m; // horizontal distance, value
    int hd = 0;
    
    q.push(root);

    cout << "Top view of the tree is\n";

    while (!q.empty())
    {
        int hd = root->hd;

        // if this node already present in the map then don't add it
        if (m.find(hd) == m.end()) // if not found then add it
            m[hd] = root->val;
        
        if (root->left)
        {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->hd = hd + 1;
            q.push(root->right);
        }

        q.pop();
        root = q.front();
    }

    for (auto e : m)
        cout << e.second << " ";
    
    return;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    topView(root);

    return 0;
}