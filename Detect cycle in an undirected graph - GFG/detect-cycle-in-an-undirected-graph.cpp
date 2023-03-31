//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool detectcycle(int src , vector<int>adj[] , unordered_map<int , bool>&visited)
    {
        visited[src] = true;
        queue<pair<int , int>>q;
        q.push({src , -1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto neighbour : adj[node])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    q.push({neighbour , node});
                }
                else if(parent != neighbour)return true;
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int , bool>visited;
        
        
        for(int i=0 ; i<V ; i++)
        {
            if(!visited[i])
            {
                if(detectcycle(i , adj , visited))return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends