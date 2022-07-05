class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==0)return n;
        int prev_sum=1;
        int total_sum = 1;
        sort(nums.begin() , nums.end());
        
        for(int i=1 ; i<n ; i++)
        {
           if(nums[i] != nums[i-1])
           {
                if(nums[i] ==  nums[i-1]+1)
                {
                    prev_sum++;
                }
               
               else
            {
                total_sum = max(total_sum , prev_sum);
                prev_sum=1;
            }
           }
           
        }
        
        total_sum = max(total_sum , prev_sum);
        
        return total_sum;
        
        
    }
};