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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int depth=1;
        while(!q.empty())
        {
            TreeNode*x = q.front();
            q.pop();
            if(x)
            {
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            else
            {
                if(!q.empty())
                {
                    q.push(NULL);
                    depth++;
                }
            }
        }
        
        return depth;
    }
};