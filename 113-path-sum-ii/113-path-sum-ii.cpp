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
        
        targetSum-=root->val;
        temp.push_back(root->val);
        
        if(targetSum==0 and !root->right and !root->left)
        {
            ans.push_back(temp);
            return;
        }
        
        if(root->left)
        {
            code(root->left , targetSum , ans , temp);
            temp.pop_back();
        }
        if(root->right)
        {
            code(root->right , targetSum , ans , temp);
            temp.pop_back();
        }
        else return;
        
        
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