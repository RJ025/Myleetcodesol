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
    int digit=0;
    void code(TreeNode*root , int &sum)
    {
        
        if(!root)return;
        
        digit = digit*10+root->val;
        if(!root->left and !root->right)
        {
            sum+=digit;
        }
        code(root->left , sum);
        code(root->right , sum);
        digit/=10;
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        
        int sum =0;
        code(root , sum);
        
        return sum;
    }
};