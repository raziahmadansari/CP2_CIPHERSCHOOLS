// https://leetcode.com/problems/diameter-of-binary-tree/


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
    int calculateMaxDiameter(TreeNode* root, int& d)
    {
        if (root == nullptr)
            return 0;
        
        int left_height = calculateMaxDiameter(root->left, d);
        int right_height = calculateMaxDiameter(root->right, d);
        d = max(d, left_height + right_height);
        return max(left_height, right_height) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateMaxDiameter(root, diameter);
        return diameter;
    }
};