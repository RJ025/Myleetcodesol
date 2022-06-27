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
    bool match(TreeNode*left_tree , TreeNode*right_tree)
    {
        if(!left_tree and !right_tree)return true;
        if(!left_tree and right_tree)return false;
        if(left_tree and !right_tree)return false;
        if(left_tree->val != right_tree->val)return false;
        
        return match(left_tree->left , right_tree->right) and match(left_tree->right , right_tree->left);
            
    }
    bool isSymmetric(TreeNode* root) {
        
        if(!root)return false;
        
        return match(root->left , root->right);
        
    }
};