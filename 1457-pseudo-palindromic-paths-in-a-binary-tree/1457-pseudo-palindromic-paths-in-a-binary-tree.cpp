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
    
    void code(TreeNode*root , unordered_map<int , int>&mpp , int&count)
    {
        if(!root)return;
        
        mpp[root->val]++;
        if(!root->left and !root->right)
        {
            int odd =0;
            
            for(auto p : mpp)
            {
                if(p.second%2!=0)
                    odd++;
            }
            if(odd<=1)count++;
        }
        
        code(root->left , mpp , count);
        code(root->right , mpp , count);
        mpp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int count =0;
        unordered_map<int , int>mpp;
        
        code(root , mpp , count);
        
        return count;
    }
};