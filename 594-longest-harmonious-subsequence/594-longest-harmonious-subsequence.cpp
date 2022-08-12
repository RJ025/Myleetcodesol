class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        
        set<int>s;
        unordered_map<int , int>mpp;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            mpp[nums[i]]++;
            s.insert(nums[i]);
        }
        
        int ans = INT_MIN;
        
        for(auto x : s)
        {
            if(mpp.find(x)!=mpp.end() and mpp.find(x+1)!=mpp.end())
                ans = max(ans , mpp[x]+mpp[x+1]);
        }
        
        if(ans==INT_MIN)return 0;
        
        return ans;
    }
};