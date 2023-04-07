//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char , int>mpp;
	    int ans=0;
	    
	    for(auto p : pat)mpp[p]++;
	    
	    int count=mpp.size();
	    int i=0 , j=0;
	    int k=pat.length();
	    int n=txt.length();
	    while(j<n)
	    {
	        if(mpp.find(txt[j])!=mpp.end())
	        {
	            mpp[txt[j]]--;
	            if(mpp[txt[j]]==0)count--;
	        }
	        if((j-i+1)<k)j++;
	        else if((j-i+1)==k)
	        {
	            if(count==0)ans++;
	                if(mpp.find(txt[i])!=mpp.end())
	                {
	                    mpp[txt[i]]++;
	                    if(mpp[txt[i]]==1)count++;
	                }

	            i++;
	            j++;
	        }
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends