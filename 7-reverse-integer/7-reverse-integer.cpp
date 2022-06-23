class Solution {
public:
    int reverse(int x) {
        long long int ans=0;
        string s;
        s = (to_string)(x);
        int n = s.length();
        int y = stoi(s);
        while(y!=0)
        {
            ans = (ans*10)+(y%10);
            y/=10;
        }
        
        if(ans>INT_MAX || ans<INT_MIN)return 0;
        
        return ans;
    }
};