//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        
        queue<pair<pair<int , int> , int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i , j} , 0});
                    visited[i][j]=2;
                }
                else visited[i][j]=0;
            }
        }
        
        int tim = INT_MIN;
        int row[] = {-1 , 0 , 1 , 0};
        int col[] = {0 , 1 , 0 , -1};
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tim = max(tim , t);
            
            for(int i=0 ; i<4 ; i++)
            {
                int nrow = r+row[i];
                int ncol = c+col[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and visited[nrow][ncol]!=2)
                {
                    visited[nrow][ncol]=2;
                    q.push({{nrow , ncol} , t+1});
                }
            }
            
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==1 and visited[i][j]!=2)return -1;
            }
        }
        
        return tim;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends