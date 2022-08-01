class Solution {
public:
    
    bool ispalin(string&s , int start , int end)
    {
        while(start < end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    
    int solve(string&s , int start , int end , vector<vector<int>>&dp)
    {
//         base case
        if(start >= end)
            return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        if(ispalin(s , start , end))
            return dp[start][end]=0;
        
        //recusrive case
        
        int ans = INT_MAX;
        for(int i=start ; i<end ; i++)
        {
            if(ispalin(s , start , i))
            {
                int chotekecount = solve(s , i+1 , end , dp);
                int totalcount = 1+chotekecount;
                ans = min(ans , totalcount);
            }
        }
        return  dp[start][end] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        if(n==0)return 0;
        
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        
        return solve(s , 0 , n-1 , dp);
    }
};