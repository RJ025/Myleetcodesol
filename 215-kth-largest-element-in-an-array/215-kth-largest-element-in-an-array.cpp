class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        
        priority_queue<int>q;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            q.push(nums[i]);
        }
        int ans;
        for(int i=0 ; i<k ; i++)
        {
            ans = q.top();
            q.pop();
        }
        
        return ans;
    }
};