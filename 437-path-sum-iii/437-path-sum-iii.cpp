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
    int count=0;
    
    void code(TreeNode*root , int targetSum , long long int sum)
    {
        if(!root) return;
        if(sum== targetSum)count++;
        
        if(root->left)code(root->left , targetSum , sum+root->left->val);
        if(root->right)code(root->right , targetSum , sum+root->right->val);
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        
        
        code(root , targetSum , root->val);
        pathSum(root->left , targetSum);
        pathSum(root->right , targetSum);
        
        return count;
        
    }
};