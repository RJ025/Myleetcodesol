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
    int i=0;
    
    TreeNode*buildtree(vector<int>&preorder , vector<int>&inorder , int s , int e)
    {
        if(s>e)return NULL;
        
        TreeNode*root = new TreeNode(preorder[i++]);
        int k=-1;
        for(int j=s ; j<=e ; j++)
        {
            if(root->val == inorder[j])
            {
                k=j;
            }
        }
        
        root->left = buildtree(preorder , inorder , s , k-1);
        root->right = buildtree(preorder , inorder , k+1 , e);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode*root = NULL;

        if(preorder[0]==-1)
        {
            root = new TreeNode(-1);
            return root;
        }
        
        root = buildtree(preorder , inorder , 0 , n-1);
        
        return root;
    }
};