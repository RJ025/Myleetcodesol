class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        if(n<=1)return 1;
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>q;
        
        for(int i=0 ; i<n ; i++)
        {
            q.push({ratings[i] , i});
        }
        
        vector<int>c(n , 1);
        
        while(!q.empty())
        {
            int rank = q.top().first;
            int i = q.top().second;
            q.pop();
            
            if(i-1>=0 and ratings[i] > ratings[i-1])
            {
                c[i] = c[i-1]+1;
            }
            
            if(i+1<n and ratings[i] > ratings[i+1])
            {
                if(c[i] <= c[i+1])
                {
                    c[i] = c[i+1]+1;
                }
            }
        }
        
         int sum=0;
            
            for(auto &itr : c)
            {
                sum+=itr;
            }
            
            return sum;
    }
};