// https://leetcode.com/problems/cousins-in-binary-tree/


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
    TreeNode* xParent = nullptr, *yParent = nullptr;
    int xDepth = -1, yDepth = -2;
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, x, y, 0);
        return (xDepth == yDepth) && (xParent != yParent);
    }
    
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int depth)
    {
        if (root == nullptr)
            return;
        else if (root->val == x)
        {
            xParent = parent;
            xDepth = depth;
        }
        else if (root->val == y)
        {
            yParent = parent;
            yDepth = depth;
        }
        else
        {
            dfs(root->left, root, x, y, depth + 1);
            dfs(root->right, root, x, y, depth + 1);
        }
    }
};