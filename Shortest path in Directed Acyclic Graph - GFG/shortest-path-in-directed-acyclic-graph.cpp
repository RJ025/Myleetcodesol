//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    void dfs(int src , unordered_map<int , bool>&visited , stack<int>&st , unordered_map<int , list<pair<int , int>>>&adjlist)
    {
        visited[src]=true;
        
        for(auto neighbour : adjlist[src])
        {
            if(!visited[neighbour.first])
            {
                dfs(neighbour.first , visited , st , adjlist);
            }
        }
        
        st.push(src);
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int , list<pair<int , int>>>adjlist;
        
        for(int i=0 ; i<M ; i++)
        {
            adjlist[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        
        stack<int>st;
        unordered_map<int , bool>visited;
        
        for(int i=0 ; i<N ; i++)
        {
            if(!visited[i])
            {
                dfs(i , visited , st , adjlist);
            }
        }
        
        vector<int>distance(N);
        for(int i=0 ; i<N ; i++)distance[i]=1e9;
        distance[0]=0;
        while(!st.empty())
        {
            int node =st.top();
            st.pop();
            
            for(auto it : adjlist[node])
            {
                int v = it.first;
                int wt = it.second;
                
                if(distance[node]+wt < distance[v])
                {
                    distance[v] = distance[node]+wt;
                }
                // else distance[v]=-1;
            }
        }
        
        for(int i=0 ; i<N ; i++)
        {
            if(distance[i]==1e9)distance[i]=-1;
        }
        
        return distance;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends