class Solution {
public:
    void solve(vector<int>nums , vector<vector<int>>&ans , vector<int>temp , int i)
    {
//         base case
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        } 
//         recursive case
        solve(nums , ans , temp , i+1);
        temp.push_back(nums[i]);
        solve(nums , ans , temp , i+1);
        temp.pop_back();
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        
        sort(nums.begin() , nums.end());
        
        solve(nums , ans , temp , 0);
        set<vector<int>>s(ans.begin() , ans.end());
        ans.clear();
        
        for(auto a : s)
        {
            ans.push_back(a);
        }
        
        return ans;
        
        // return ans;
    }
};