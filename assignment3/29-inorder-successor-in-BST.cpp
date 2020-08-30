// https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/

#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:

    int val;
    Node* left;
    Node* right;

    Node(int val = 0)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root, int val)
{
    // cout << "insert\n";
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
    // cout << "buildBST\n";

    Node* root = nullptr;
    for (int i = 0; i < v.size(); i++)
    {
        root = insert(root, v[i]);
    }
    return root;
}

void printInorder(Node* root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
    return;
}

Node* minNode(Node* root)
{
    while (root->left)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* temp)
{
    if (temp->right != nullptr)
        return minNode(temp->right);
    
    Node* successor = nullptr;
    while (root)
    {
        if (temp->val < root->val)
        {
            successor = root;
            root = root->left;
        }
        else if (temp->val > root->val)
            root = root->right;
        else
            break;
    }
    return successor;
}

int main()
{
    vector<int> v{20, 8, 22, 4, 12, 10, 14};
    Node* root = buildBST(v);

    cout << "Inorder Traversal : ";
    printInorder(root);
    cout << "\n";

    Node* temp = root->left->right->right;
    cout << "inorder successor of (" << temp->val << ") is : ";
    cout << inorderSuccessor(root, temp)->val;

    return 0;
}