class Solution {
public:
    void solve(vector<int>nums , vector<vector<int>>&ans , vector<int>&temp , int k , int j)
    {
//         base case
        if(k==0)
        {
            ans.push_back(temp);
            return;
        }
        
        
//         recursive case
      for(int i=j ; i<nums.size() ; i++)
      {
          temp.push_back(nums[i]);
          k--;
          solve(nums , ans , temp , k , i+1);
          k++;
          temp.pop_back();
      }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=0 ; i<n ; i++)nums.push_back(i+1);
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(nums , ans , temp , k , 0);
        
        return ans;

    }
};