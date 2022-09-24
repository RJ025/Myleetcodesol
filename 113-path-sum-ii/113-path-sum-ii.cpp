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
    void code(TreeNode*root , int targetSum , vector<vector<int>>&ans , vector<int>&temp)
    {
        
       if(!root)return;
        
        temp.push_back(root->val);
        
        if(!root->left and !root->right and targetSum==root->val) ans.push_back(temp);
        
        code(root->left , targetSum-root->val , ans , temp);
        code(root->right , targetSum-root->val , ans , temp);
        
        temp.pop_back();

        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        if(!root)return ans;
        
        // int sum=0;
        
        code(root , targetSum , ans , temp);
        
        return ans;
    }
};