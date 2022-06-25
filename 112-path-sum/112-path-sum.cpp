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
    int sum=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
      sum+=root->val;
      if(root->left==NULL && root->right==NULL )
      {
        if(sum==targetSum) return true;
        else{ sum-=root->val; return false;}
      }
     bool left= hasPathSum(root->left,targetSum);
     bool right= hasPathSum(root->right,targetSum);
         sum -= root->val;
      
       return left|| right; 
    }
};