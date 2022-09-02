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
    
    void code(TreeNode*root , int&cnt , int prev_max)
    {
        if(!root)return;
        
        if(root->val >= prev_max)
        {
            cnt++;
            prev_max = root->val;
        }
        
        code(root->left , cnt , prev_max);
        code(root->right , cnt , prev_max);
        
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        
        int cnt = 0;
        
        code(root , cnt , root->val);
        
        return cnt;
        
    }
};