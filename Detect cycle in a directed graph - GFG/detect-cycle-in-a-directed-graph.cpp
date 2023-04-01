//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool dfs(vector<int>adj[] , vector<int>&visited , vector<int>&path_visited , int src)
    {
        visited[src]=1;
        path_visited[src]=1;
        
        for(auto neighbour : adj[src])
        {
            if(!visited[neighbour])
            {
                if(dfs(adj , visited , path_visited , neighbour))return true;
            }
            else if(path_visited[neighbour]==1)return true;
        }
        
        path_visited[src]=0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V , 0);
        vector<int>path_visited(V , 0);
        
        for(int i=0 ; i<V ; i++)
        {
            if(!visited[i])
            {
                if(dfs(adj , visited , path_visited , i))return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends