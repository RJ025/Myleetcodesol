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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int>temp;
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode*x = q.front();
            q.pop();
            if(x)
            {
                temp.push_back(x->val);
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            else
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        
        return ans;
            
    }
};