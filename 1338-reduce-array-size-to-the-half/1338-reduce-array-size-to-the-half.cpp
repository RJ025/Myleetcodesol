class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , int>mpp;
        sort(arr.begin() , arr.end());
        
        for(int i=0 ; i<n ; i++)
        {
            mpp[arr[i]]++;
        }
        
        priority_queue<pair<int , int> , vector<pair<int , int>>>q;
        
        for(auto p : mpp)
        {
            q.push({p.second , p.first});
        } 
        // if(q.size()==1)return 1;
        int half_size=0;
        int count=0;
        
        while(!q.empty())
        {
            int f = q.top().first;
            q.pop();
            count++;
            half_size+=f;
            if(half_size>=n/2)
                break;
            
            
            
        }
        
        
        
        return count;
    }
};