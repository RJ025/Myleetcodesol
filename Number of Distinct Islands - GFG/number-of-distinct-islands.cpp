//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    void dfs(vector<vector<int>>& grid , vector<vector<int>>&visited , vector<pair<int , int>>&coord , int r , int c , int*row , int*col , int row0 , int col0)
    {
        visited[r][c]=1;
        coord.push_back({r-row0 , c-col0});
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0 ; i<4 ; i++)
        {
            int nrow = r+row[i];
            int ncol = c+col[i];
            
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !visited[nrow][ncol] and grid[nrow][ncol]==1)
            {
                dfs(grid , visited , coord , nrow , ncol , row , col , row0 , col0);
            }
        }
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n , vector<int>(m , 0));
        set<vector<pair<int , int>>>s;
        
        int row[]={-1 , 0 , 1 , 0};
        int col[] = {0 , -1 , 0 , 1};
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
               
                if(!visited[i][j] and grid[i][j]==1)
                {
                    vector<pair<int , int>>coord;
                    dfs(grid , visited , coord , i , j , row , col , i , j);
                    s.insert(coord);
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends