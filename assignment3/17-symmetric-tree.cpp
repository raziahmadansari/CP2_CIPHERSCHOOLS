// https://leetcode.com/problems/symmetric-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return checkSymmetricity(root->left, root->right);
    }
    
    bool checkSymmetricity(TreeNode* a, TreeNode* b)
    {
        if (a == nullptr && b == nullptr)
            return true;
        else if (a == nullptr || b == nullptr)
            return false;
        
        if (a->val != b->val)
            return false;
        
        return checkSymmetricity(a->left, b->right) && checkSymmetricity(a->right, b->left);
    }
};