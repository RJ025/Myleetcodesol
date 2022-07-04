class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1)return 1;
        
        vector<int>l_candy(n , 1);
        vector<int>r_candy(n , 1);
        
        for(int i=1 ; i<n ; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                l_candy[i] = l_candy[i-1]+1;
            }
        }
        
        for(int i=n-2 ; i>=0 ; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                r_candy[i] = r_candy[i+1]+1;
            }
        }
        
        int ans=0;
        
        for(int i=0 ; i<n ; i++)
        {
            ans+=max(l_candy[i] , r_candy[i]);
        }
        
        return ans;
    }
};