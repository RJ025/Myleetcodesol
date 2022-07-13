class Solution {
public:
    
//     void code(vector<int>nums , int k , int&count , int sum , int i)
//     {
//         if(sum%k==0)
//         {
//             count++;
//             return;
//         }
        
//         for(int j=i ; j<nums.size() ; j++)
//         {
//             if(nums[j]<=k)
//             {
//                 sum+=nums[j];
//                 code(nums , k , count , sum , j+1);
//                 sum-=nums[j];
//                 code(nums , k , count , sum , j+1);
//             }
//         }
//     }
    
    int subarraysDivByK(vector<int>& nums, int k) {
        if(nums.size()==0)return 0;
        // if(nums.size()==1 and nums[0]<k)return 0;
        int n = nums.size();
        int count=0;
//         vector<int>prefix(n+1);
        
//         prefix[0]=0;
        
//         for(int i=0 ; i<n ; i++)
//         {
//             prefix[i+1] = prefix[i]+nums[i];
//         }
//         prefix[n] = prefix[n-1]+nums[n-1];
        
        // for(int i=0 ; i<n+1 ; i++)
        // {
        //     for(int j=i+1 ; j<n+1 ; j++)
        //     {
        //         if((prefix[j]-prefix[i])%k==0)
        //             count++;
        //     }
        // }
        unordered_map<int , int>mpp;
        int sum=0 , rem=0;
        
        for(int i=0 ; i<n ; i++)
        {
            sum+=nums[i];
            rem=(sum%k+k)%k;
            if(rem==0)count++;
            if(mpp.find(rem)!=mpp.end())count+=mpp[rem];
            mpp[rem]++;
        }
        
        
        
        return count;
    }
};