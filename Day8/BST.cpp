#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data = 0)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildBST(Node* root, int d)
{
    if (root == nullptr)
        return new Node(d);
    
    if (d < root->data)
        root->left = buildBST(root->left, d);
    else
        root->right = buildBST(root->right, d);
    return root;
}

bool find(Node* root, int val)
{
    if (root == nullptr)
        return false;
    
    if (root->data == val)
        return true;
    
    if (val < root->data)
        return find(root->left, val);
    return find(root->right, val);
}

void preorder(Node* root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

Node* deleteNode(Node* root, int val)
{
    if (root == nullptr)
        return root;
    
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        // node with 0 children
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }

        // node with 1 child
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
        // node with 2 children
        else
        {
            Node* nextBig = root->right;
            while (!nextBig->left)
                nextBig = nextBig->left;
            root->data = nextBig->data;
            
            root->right = deleteNode(root->right, root->data);
            return root;
        }
    }
    return root;
}

int main()
{
    vector<int> v{10, 8, 12, 2, 9, 11, 15};
    
    Node* root = nullptr;
    for (auto e : v)
        root = buildBST(root, e);

    preorder(root);

    cout << endl;
    if (find(root, 88))
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    deleteNode(root, 10);
    cout << "Node with value = 10 deleted" << endl;
    preorder(root);
    
    return 0;
}