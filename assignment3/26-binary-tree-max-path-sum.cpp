// https://leetcode.com/problems/binary-tree-maximum-path-sum/


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
    int maxSum = INT_MIN;
    
    int helper(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int leftSum = max(helper(root->left), 0);
        int rightSum = max(helper(root->right), 0);
        
        maxSum = max(maxSum, root->val + leftSum + rightSum);
        
        return root->val + max(leftSum, rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};