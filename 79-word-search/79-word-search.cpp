class Solution {
public:
    
    bool code(vector<vector<char>>&board , int i , int j , int n , int m , string word , int k)
    {
//         base case
        if(k==word.length())
            return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[k])
            return false;
        
        
//         recursive case
        char ch = board[i][j];
        board[i][j] = '.';
        int x[4] = {0 , 1 , 0 , -1};
        int y[4] = {1 , 0 , -1 , 0};
        bool ans = false;
        for(int l=0 ; l<4 ; l++)
        {
            int ni = i+x[l];
            int nj = j+y[l];
            ans = code(board , ni , nj , n , m , word , k+1);
            if(ans == true)
                break;
        }
        board[i][j] = ch;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m; j++)
            {
                bool ans = code(board , i , j , n , m , word , 0);
                if(ans)return true;;
                
            }
        }
        return false;
    }
};