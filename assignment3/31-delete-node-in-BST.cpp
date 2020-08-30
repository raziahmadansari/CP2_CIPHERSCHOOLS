#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root, int val)
{
    if (root == nullptr)
        return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

Node* buildBST(vector<int>& v)
{
    Node* root = nullptr;
    for (int i = 0; i < v.size(); i++)
        root = insert(root, v[i]);
    return root;
}

void inorder(Node* root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

Node* minValue(Node* root)
{
    while (root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val)
{
    if (root == nullptr)
        return root;
    
    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
    
    else
    {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = minValue(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;    
}

int main()
{
    vector<int> v{ 50, 30, 70, 20, 40, 60, 80 };
    Node* root = buildBST(v);

    inorder(root);
    cout << endl;
    deleteNode(root, 20);
    inorder(root);

    return 0;
}