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
    
    void code(TreeNode* root , priority_queue<int , vector<int> , greater<int>>&q)
    {
        if(!root)return;
            
         q.push(root->val);

        
        code(root->left , q);
        code(root->right , q);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        priority_queue<int , vector<int> , greater<int>>q;
        
        code(root , q);
        k=k-1;
        while(k--)q.pop();
        
        int ans = q.top();
        
        return ans;
        
    }
};