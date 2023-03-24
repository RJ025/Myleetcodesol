//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        if(S.length()==0||S.length()==1)return S;
        unordered_map<char , int>mpp;
        
        for(int i=0 ; i<S.length() ; i++)mpp[S[i]]++;
        
        string ans="";
        
        int i=0 , j=S.length()-1;
        bool flag = false;
        set<int>st;
        while(i<j)
        {
            if(!flag)
            {
                if(mpp[S[i]]>1)
                {
                    mpp[S[i]]--;
                    st.insert(i);
                    flag=!flag;
                }
                i++;
            }
            else
            {
                if(mpp[S[j]]>1)
                {
                    mpp[S[j]]--;
                    st.insert(j);
                    flag=!flag;
                }
                j--;
            }
        }
        
        for(int i=0 ; i<S.length() ; i++)
        {
            if(!st.count(i))ans+=(S[i]);
        }
        
        if(flag)reverse(ans.begin() , ans.end());
            
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends