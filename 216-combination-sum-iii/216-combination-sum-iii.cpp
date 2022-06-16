class Solution {
public:
    
    void solve(vector<int>&num , vector<int>&temp , vector<vector<int>>&ans , int k , int n , int idx)
    {
//         base case
        // if(k==0)
        // {
        //     return;
        // }
        if(k==0 and n==0)
        {
            ans.push_back(temp);
            return;
        }
//         recursive case
        // while(k>=0)
        // {
            for(int j=idx ; j<num.size() ; j++)
            {
                if(n>=num[j])
                {
                    temp.push_back(num[j]);
                    k--;
                    solve(num , temp , ans , k , n-num[j] , j+1);
                    k++;
                    temp.pop_back();
                }
            }
        // }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>num;
        for(int i=1 ; i<=9 ; i++)
        {
            num.push_back(i);
        }

        vector<int>temp;
        vector<vector<int>>ans;
        
        solve(num , temp , ans , k , n , 0);
        
        return ans;
        
    }
};