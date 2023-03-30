//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    void bfs(int row , int col , vector<vector<int>>&visited , vector<vector<char>>& grid)
    {
        visited[row][col]=1;
        queue<pair<int , int>>q;
        q.push({row , col});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int del_row=-1  ; del_row<=1 ; del_row++)
            {
                for(int del_col=-1 ; del_col<=1 ; del_col++)
                {
                    int nrow = row+del_row;
                    int ncol = col+del_col;
                    
                    if(nrow<n and nrow>=0 and ncol<m and ncol>=0 and visited[nrow][ncol]==0 and grid[nrow][ncol]=='1')
                    {
                        visited[nrow][ncol]=1;
                        q.push({nrow , ncol});
                    }
                }
            }
        }
        
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n , vector<int>(m , 0));
        int cnt=0;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(!visited[i][j] and grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i , j , visited , grid);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends