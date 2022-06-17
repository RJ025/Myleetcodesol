class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        if(nums1.size()==0 || nums2.size()==0)return ans;
       // ort(nums1.begin() , num ss1.end());
       //  sort(nums2.begin() , nums2.end());

        unordered_map<int, int>mpp;
        for(int i=0 ; i<nums1.size() ; i++)
        {
            mpp[nums1[i]]++;
        }
        
        for(int i=0 ; i<nums2.size() ; i++)
        {
            if(mpp[nums2[i]]!=0)
            {
                ans.push_back(nums2[i]);
                mpp[nums2[i]]--;
            }
        }
        
        // for(auto x : mpp)
        // {
        //     if(mpp[x.first] == 0)
        //     {
        //         ans.push_back(x.first);
        //     }
        // }
        return ans;
    }
};