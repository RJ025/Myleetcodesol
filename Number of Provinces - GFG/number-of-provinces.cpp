//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfshelper(int src , unordered_map<int , bool>&visited , unordered_map<int , list<int>>&adjlist)
    {
        visited[src]=true;
        for(auto neighbour : adjlist[src])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour , visited , adjlist);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        if(adj.size()==0)return 0;
        unordered_map<int , list<int>>adjlist;
        
        for(int i=0 ; i<V ; i++)
        {
            for(int j=0 ; j<V ; j++)
            {
                if(adj[i][j]==1)
                {
                    adjlist[i].push_back(j);
                    // adjlist[j].push_back(i);
                }
            }
        }
        
        unordered_map<int , bool>visited;
        
        dfshelper(0 , visited , adjlist);
        int component=1;
        for(auto p : adjlist)
        {
            if(!visited[p.first])
            {
                component++;
                dfshelper(p.first , visited , adjlist);
            }
        }
        
        return component;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends