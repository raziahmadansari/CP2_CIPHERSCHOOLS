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

int largestBSTUtil(Node* node, int *min_ref, int *max_ref, int *max_size_ref, bool *is_bst_ref)
{
    /* Base Case */
    if (node == NULL)  
    {  
        *is_bst_ref = 1; // empty tree is BST  
        return 0; // Size of the BST is 0  
    }  
      
    int min = INT_MAX;  
      
    /* A flag variable for left subtree property  
        i.e., max(root->left) < root->data */
    bool left_flag = false;  
      
    /* A flag variable for right subtree property  
        i.e., min(root->right) > root->data */
    bool right_flag = false;  
      
    int ls, rs; // To store sizes of left and right subtrees  
      
    /* Following tasks are done by  
    recursive call for left subtree  
        a) Get the maximum value in left  
        subtree (Stored in *max_ref)  
        b) Check whether Left Subtree is  
        BST or not (Stored in *is_bst_ref)  
        c) Get the size of maximum size BST  
        in left subtree (updates *max_size) */
    *max_ref = INT_MIN;  
    ls = largestBSTUtil(node->left, min_ref, max_ref, 
                        max_size_ref, is_bst_ref);  
    if (*is_bst_ref == 1 && node->val > *max_ref)  
        left_flag = true;  
      
    /* Before updating *min_ref, store the min 
    value in left subtree. So that we have the 
    correct minimum value for this subtree */
    min = *min_ref;  
      
    /* The following recursive call 
    does similar (similar to left subtree)  
    task for right subtree */
    *min_ref = INT_MAX;  
    rs = largestBSTUtil(node->right, min_ref,  
                        max_ref, max_size_ref, is_bst_ref);  
    if (*is_bst_ref == 1 && node->val < *min_ref)  
        right_flag = true;  
      
    // Update min and max values for  
    // the parent recursive calls  
    if (min < *min_ref)  
        *min_ref = min;  
    if (node->val < *min_ref) // For leaf nodes  
        *min_ref = node->val;  
    if (node->val > *max_ref)  
        *max_ref = node->val;  
      
    /* If both left and right subtrees are BST.  
    And left and right subtree properties hold 
    for this node, then this tree is BST.  
    So return the size of this tree */
    if(left_flag && right_flag)  
    {  
        if (ls + rs + 1 > *max_size_ref)  
            *max_size_ref = ls + rs + 1;  
        return ls + rs + 1;  
    }  
    else
    {  
        // Since this subtree is not BST,  
        // set is_bst flag for parent calls  
        *is_bst_ref = 0;  
        return 0;  
    }  
}

int largestBST(Node* node)
{
    int min_right_subtree = INT_MAX;
    int max_left_subtree = INT_MIN;

    int max_size = 0; // size of largest BST;
    bool is_bst = false;

    largestBSTUtil(node, &min_right_subtree, &max_left_subtree, &max_size, &is_bst);

    return max_size;
}

int main()
{
    vector<int> v{ 5, 2, 4, 1, 3 };
    Node* root = buildBST(v);

    cout << root->val << endl;

    cout << largestBST(root);

    return 0;
}