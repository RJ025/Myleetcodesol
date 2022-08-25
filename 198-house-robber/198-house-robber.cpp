class Solution {
public:
    
    int rec(vector<int>&nums , int i)
    {
        if(i>=nums.size())return 0;
        
        int inc = rec(nums , i+2) + nums[i];
        int dec = rec(nums , i+1) + 0;
        
        return max(inc , dec);
    }
    
    int top(vector<int>&nums , int i , vector<int>&dp)
    {
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        
        int inc = top(nums , i+2 , dp) + nums[i];
        int dec = top(nums , i+1 , dp) + 0;
        
        return dp[i] = max(inc , dec);
        
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        
        vector<int>dp(nums.size() , -1);
        
        return top(nums , 0 , dp);
        
        // return rec(nums , 0);
    }
};