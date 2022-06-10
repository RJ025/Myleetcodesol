class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int , int>mpp;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            mpp[nums[i]]++;
        }
        
        int count1=0;
        
        if(k==0)
        {
            for(auto x : mpp)
            {
                if(x.second > 1)count1++;
            }
            return count1;
        }
        
        for(auto x: mpp)
        {
            if(mpp.count(x.first-k))count1++;
        }
        
        return count1;
    }
};