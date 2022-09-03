class Solution {
public:
    
    int digitCount(int x)
    {
        int cnt=0;
        while(x)
        {
            cnt++;
            x/=10;
        }
        return cnt;
    }
    
    void solve(int curr , int n , int k , vector<int>&ans)
    {
//         base case
        if(digitCount(curr)==n)
        {
            ans.push_back(curr);
            return;
        }
        
        
        
//         recursive case
        for(int i=0 ; i<=9 ; i++)
        {
            int last_digit = curr%10;
            if(abs(last_digit-i)==k)
            {
                solve(curr*10+i , n , k , ans);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        
        if(n==1)ans.push_back(0);
        
        for(int i=1 ; i<=9 ; i++)
        {
            solve(i , n , k , ans);
        }
        
        return ans;
        
    }
};