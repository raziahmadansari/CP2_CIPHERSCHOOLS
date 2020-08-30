// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


/*
 *RUNTIME ERROR
 *
 */

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
    int find(vector<int>& inorder, int inStart,  int inEnd, int val)
    {
        int i = 0;
        for (i = inStart; i <= inEnd; i++)
            if (inorder[i] == val)
                return i;
        return i;
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd)
    {
        static int preIndex = 0;
        
        if (inStart > inEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        if (inStart == inEnd)
            return root;
        
        int inIndex = find(inorder, inStart, inEnd, root->val);
        
        root->left = helper(preorder, inorder, inStart, inIndex - 1);
        root->right = helper(preorder, inorder, inIndex + 1, inEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1);
    }
};



/*
 *WITHOUT RUNTIME ERROR
 *
 */

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return builTreeHelper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }

    TreeNode* builTreeHelper(vector<int>& preorder, int sp, int ep, vector<int>& inorder, int si, int ei) {
        if (sp == ep) return nullptr;
        TreeNode* root = new TreeNode(preorder[sp]);
        int dis = find(inorder.begin()+si,inorder.begin()+ei,preorder[sp]) - inorder.begin() - si;
        root->left = builTreeHelper(preorder,sp+1,sp+1+dis,inorder,si,si+dis);
        root->right = builTreeHelper(preorder,sp+1+dis,ep,inorder,si+dis+1,ei);
        return root;
    }
};