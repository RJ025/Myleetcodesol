class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==0)return nums;
        if(nums.size()==1)return nums;
        
        vector<int>ans(k);
        sort(nums.begin() , nums.end());
        priority_queue<pair<int , int>>q;
        int curr = nums[0] , cnt=1;
        
        for(int i=1 ; i<nums.size() ; i++)
        {
            if(nums[i] != nums[i-1])
            {
                q.push({cnt , curr});
                cnt=1;
                curr = nums[i];
            }
            else
            {
                cnt++;
            }
        }
        
        q.push({cnt , nums[nums.size()-1]});
        
        for(int i=0 ; i<k ; i++)
        {
            ans[i] = q.top().second;
            q.pop();
        }
        
        return ans;
    }
};