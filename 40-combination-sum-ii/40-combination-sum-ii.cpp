class Solution {
public:
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
            if(idx<i and candidates[i] == candidates[i-1])
            {
                continue;
            }
            if(candidates[i] <= target)
            {
                temp.push_back(candidates[i]);
                solve(candidates , temp , ans , target - candidates[i] , i+1);
                temp.pop_back();
            }
            // else
            // {
            //     solve(candidates , temp , ans , target , i+1);
            // }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin() , candidates.end());
        
        solve(candidates , temp , ans , target , 0);
        
        return ans;
    }
};