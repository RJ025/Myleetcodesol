//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        stack<pair<int , int>>st;
        st.push({color[0] , radius[0]});
        for(int i=1 ; i<n ; i++)
        {
            if(!st.empty() and st.top().first==color[i] and st.top().second==radius[i])
            {
                while(!st.empty() and st.top().first==color[i] and st.top().second==radius[i])
                {
                    st.pop();
                }
            }
            else 
            st.push({color[i] , radius[i]});
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends