class Solution {
public:
    void solve(vector<int>nums , vector<vector<int>>&ans , vector<int>&temp , int i)
    {
//         base case
        if(i==nums.size())
        {
            ans.push_back(nums);
        }
        
//         recursive case
        for(int j=i ; j<nums.size() ; j++)
        {
            swap(nums[i] , nums[j]);
            solve(nums , ans , temp , i+1);
            swap(nums[i] , nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
    }
};