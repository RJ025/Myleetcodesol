class Solution {
public:
    
    int code(int n , vector<int>&dp , int k)
    {
        if(n==0)
            return 1;
        if(dp[n]!=0)
            return dp[n];
        
        int ways =0;
        for(int i=1 ; i<=k ; i++)
        {
            if(n-i>=0)
            ways+=code(n-i , dp , k);
        }
        
        return dp[n] = ways;
        
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+1 , 0);
        
        return code(n , dp , 2);
    }
};