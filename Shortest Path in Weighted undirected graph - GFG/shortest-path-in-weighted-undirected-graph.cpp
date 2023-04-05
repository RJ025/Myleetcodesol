//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int>distance(n+1 , 1e9);
        vector<int>parent(n+1);
        for(int i=1 ; i<=n ; i++)parent[i]=i;
        
        unordered_map<int , list<pair<int , int>>>adjlist;
        
        for(int i=0 ; i<edges.size() ; i++)
        {
            adjlist[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            adjlist[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>q;
        q.push({0 , 1});
        distance[1]=0;
        parent[1]=1;
        
        while(!q.empty())
        {
            int node = q.top().second;
            int dis = q.top().first;
            q.pop();
            
            for(auto neighbour : adjlist[node])
            {
                int adjnode = neighbour.first;
                int wt = neighbour.second;
                if(wt+dis < distance[adjnode])
                {
                    distance[adjnode] = wt+dis;
                    parent[adjnode] = node;
                    q.push({distance[adjnode] , adjnode});
                }
            }
        }
        
        vector<int>ans;
        int node = n;
        
        while(node != parent[node])
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        if(ans.size()==1)return {-1};
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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