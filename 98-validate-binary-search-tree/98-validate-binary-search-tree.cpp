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
    
    bool isbst(TreeNode*root , long mi , long mx)
    {
        if(!root)return true;
        
        if(((root->val>mi) and (root->val < mx)) and isbst(root->left , mi , root->val) and isbst(root->right , root->val  , mx)) 
        {
            return true;
        }
        else
            return false;
            
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        if(!root->left and !root->right)return true;
        return isbst(root , LONG_MIN , LONG_MAX);
    }
};