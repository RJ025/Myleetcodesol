class Solution {
public:
    
    int code(vector<int>& nums , int target , int start , int end)
    {
//         if(start > end)return -1;
        
//         int mid = (start+end)/2;
        
//         if(nums[mid]==target)return mid;
//         else if(nums[mid] > target) code(nums , target , start , mid-1);
//         else code(nums , target , mid+1 , end);
        
        while(start <= end)
        {
            int mid = (start+end)/2;
            
            if(nums[mid]==target)return mid;
            else if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        return code(nums , target , 0 , nums.size()-1);
    }
};