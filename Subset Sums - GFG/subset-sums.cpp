// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    void code(int i , vector<int>&ans , vector<int>&arr , int N , int sum)
    {
        if(i==N)
        {
            ans.push_back(sum);
            return;
        }
        
        code(i+1 , ans , arr , N , sum+arr[i]);
        code(i+1 , ans , arr , N , sum);
        
        return;
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        
        code(0 , ans , arr , N , 0);
        
        sort(ans.begin() , ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends