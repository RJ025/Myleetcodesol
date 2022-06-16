class Solution {
    
    void solve(vector<int>& candidates , vector<int>&temp ,  vector<vector<int>>&ans , int target , int idx)
    {
//         base case
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        
//         recursive case
        for(int i=idx ; i<candidates.size() ; i++)
        {
            if(candidates[i] <= target)
            {
                temp.push_back(candidates[i]);
                solve(candidates , temp , ans , target - candidates[i] , i);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        
        solve(candidates , temp , ans , target , 0);
        return ans;
    }
};