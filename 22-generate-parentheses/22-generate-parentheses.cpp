class Solution {
public:
    void solve(vector<string>&ans , int no , int nc , int n , string s)
    {
//         base case
        if(nc==n and no==n)
        {
            ans.push_back(s);
            return;
        }
        
//         recursive case
        if(no>nc)
            solve(ans , no , nc+1 , n , s+')');
        if(n>no)
            solve(ans , no+1 , nc , n , s+'(');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int no=0 , nc=0;
        string s="";
        
        solve(ans , no , nc , n , s);
        return ans;
    }
};