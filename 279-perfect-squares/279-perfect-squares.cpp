class Solution {
public:
    
    int rec(int n)
    {
        if(n==0)return 0;
        
        int ans = INT_MAX;
        
        for(int i=1 ; i*i<=n ; i++)
        {
            ans = min(ans , 1+rec(n-i*i));
        }
        
        return ans;
    }
    
    int topdown(int n , vector<int>&dp)
    {
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        
        int ans = INT_MAX;
        
        for(int i=1 ; i*i<=n ; i++)
        {
            ans = min(ans , 1+topdown(n-i*i , dp));
        }
        
        dp[n] = ans;
        
        return dp[n];
    }
    
    int numSquares(int n) {
        
        vector<int>dp(n+1 , -1);
        return topdown(n , dp);
    }
};