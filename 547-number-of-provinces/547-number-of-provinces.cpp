class Solution {
public:
    
    void dfs(vector<vector<int>>&isConnected , int i)
    {
        // isConnected[i][j]=0;
        
        for(int k=0 ; k<isConnected[i].size() ; k++)
        {
            if(isConnected[i][k]==1){
                isConnected[i][k] = 0;
                dfs(isConnected , k);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        
        for(int i=0 ; i<isConnected.size() ; i++)
        {
            for(int j=0 ; j<isConnected[0].size() ; j++)
            {
                if(isConnected[i][j])
                {
                    provinces++;
                    dfs(isConnected , i);
                }
            }
        }
        
        return provinces;
    }
};