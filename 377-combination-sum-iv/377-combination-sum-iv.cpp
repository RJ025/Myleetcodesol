class Solution {
public:
    
    int code(vector<int>& nums, int target,  vector<int>&dp)
    {
//         base case
        if(target == 0)
        {
            return 1;
        }
        if(target<0)return 0;
        
        if(dp[target]!=-1)return dp[target];
        
        
        
//         recursive case
        int ans=0;
        for(int j=0 ; j<nums.size() ; j++)
        {
            ans+=code(nums , target-nums[j] , dp);
        }
        
        dp[target] = ans;
        
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        if(nums.size()==0)return 0;
        
        vector<int>dp(target+1 , -1);
        
        return code(nums , target,dp);
        
        // return count;
    }
};