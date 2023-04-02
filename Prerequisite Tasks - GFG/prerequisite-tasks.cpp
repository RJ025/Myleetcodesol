//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int>>&pre) {
       vector<int>adjlist[N];
        
        for(auto p : pre)
        {
            adjlist[p.first].push_back(p.second);
        }
        
        vector<int>indeg(N , 0);
        
        for(auto p : pre)
        {
            indeg[p.second]++;
        }
        
        queue<int>q;
        for(int i=0 ; i<N ; i++)
        {
            if(indeg[i]==0)q.push(i);
        }
        
        int cnt=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cnt++;
            
            for(neighbour : adjlist[node])
            {
                indeg[neighbour]--;
                if(indeg[neighbour]==0)q.push(neighbour);
            }
        }
        
        if(cnt!=N)return false;
        
        return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends