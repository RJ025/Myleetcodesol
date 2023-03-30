//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    void dfs(vector<vector<int>>&ans , vector<vector<int>>&image , int*row , int*col , int sr , int sc , int newcolor , int ini)
    {
        ans[sr][sc]=newcolor;
        int n=image.size();
        int m = image[0].size();
        // queue<pair<int , int>>q;
        // q.push({sr , sc});
        
        for(int i=0 ; i<4 ; i++)
        {
            int nrow = sr+row[i];
            int ncol = sc+col[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==ini and ans[nrow][ncol]!=newcolor)
            {
                dfs(ans , image , row , col , nrow , ncol , newcolor , ini);
            }
        }
        
        // while(!q.empty())
        // {
        //     int r = q.front().first;
        //     int c = q.front().second;
        //     q.pop();
        //     ans[r][c]=newcolor;
        //     for(int i=0 ; i<4 ; i++)
        //     {
        //         int nrow = r+row[i];
        //         int ncol = c+col[i];
        //         if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==ini and ans[nrow][ncol]!=newcolor)
        //         {
                    
        //             q.push({nrow , ncol});
        //         }
        //     }
        // }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>>ans = image;
        
        int row[] = {-1 , 0 , 1 , 0};
        int col[] = {0 , 1 , 0 , -1};
        int ini = image[sr][sc];
        
        dfs(ans , image , row , col , sr , sc , newcolor , ini);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends