#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>

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

void preorder(Node* root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
    return;
}

void inorder(Node* root)
{
    if (root == nullptr)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

void postorder(Node* root)
{
    if (root == nullptr)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    return;
}

int countNode(Node* root)
{
    // cout << "Function called" << endl;
    if (root == nullptr)
        return 0;
    
    int h1 = countNode(root->left);
    int h2 = countNode(root->right);
    return h1 + h2 + 1;
}

int height(Node* root)
{
    if (root == nullptr)
        return 0;
    
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
}

int sumOfNodes(Node* root)
{
    if (root == nullptr)
        return 0;
    
    int left = sumOfNodes(root->left);
    int right = sumOfNodes(root->right);
    return (left + right + root->data);
}

int childSum(Node*& root) // update current node with data of child + data of same node
{
    if (root == nullptr)
        return 0;
    
    /*if (root->left == nullptr && root->right == nullptr)
        return root->data;*/
    
    int left = childSum(root->left);
    int right = childSum(root->right);
    return root->data += left + right;
}

void levelOrderPrint(Node* root)
{
    if (root == nullptr)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* f = q.front();

        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << f->data << ".";
            q.pop();
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }   
    }
    return;
}

void mirrorOfBT(Node*& root)
{
    if (root == nullptr)
        return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorOfBT(root->left);
    mirrorOfBT(root->right);
    return;
}

pair<int, bool> isBalanced(Node* root)
{
    pair<int, bool> p, left, right;

    if (root == nullptr)
    {
        p.first = 0;
        p.second = true;
        return p;
    }
    
    left = isBalanced(root->left);
    right = isBalanced(root->right);

    int height = fabs(left.first - right.first) + 1;

    if (fabs(left.first - right.first) <= 1 && left.second && right.second)
        return make_pair(height, true);
    return make_pair(height, false);
}

void printkth(Node* root, int k)
{
    if (root == nullptr)
        return;
    
    if (k == 0) // root node
    {
        cout << root->data << " ";
        return;
    }
    printkth(root->left, k - 1);
    printkth(root->right, k - 1);
    return;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    cout << "Preorder  - ";
    preorder(root);
    cout << endl;

    cout << "Inorder   - ";
    inorder(root);
    cout << endl;

    cout << "Postorder - ";
    postorder(root);
    cout << endl;

    int node = countNode(root);
    cout << "Node = " << node << endl;
    cout << "Height = " << height(root) << endl;
    cout << "Sum of nodes = " << sumOfNodes(root) << endl;

    /*childSum(root);
    cout << "Preorder  - ";
    preorder(root);
    cout << endl;*/

    levelOrderPrint(root);

    /*mirrorOfBT(root);
    cout << endl;
    cout << "mirror - " << endl;
    levelOrderPrint(root);
    cout << endl;*/

    pair<int, bool> balanced = isBalanced(root);
    cout << "height = " << balanced.first << ", isBalanced - " << balanced.second << endl;

    printkth(root, 2);
    cout << endl;

    return 0;
}