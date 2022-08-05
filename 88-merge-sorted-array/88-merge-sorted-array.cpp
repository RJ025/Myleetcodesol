class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int>ans;/
        
        priority_queue<int , vector<int> , greater<int>>q;
        int i=0 , j=0;
        while(m--)
        {
            q.push(nums1[i++]);
        }
        while(n--)
        {
            q.push(nums2[j++]);
        }
        nums1.clear();
        
        while(!q.empty())
        {
            nums1.push_back(q.top());
            q.pop();
        }
        
        // return ans;
    }
};