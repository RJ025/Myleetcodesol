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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(!root)return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        double sum = 0;     
        int cnt =0;
        while(!q.empty())
        {
            TreeNode*x = q.front();
            q.pop();
            
            if(x)
            {
                sum+=x->val;
                cnt++;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            else
            {
                double avg;
                avg = sum/cnt;
                ans.push_back(avg);
                if(!q.empty())
                    q.push(NULL);
                    
                avg=0;
                cnt=0;
                sum=0;
               
            }
            
        }
        
        return ans;
        
    }
};