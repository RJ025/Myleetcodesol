class Solution {
public:
    
    bool issafetoput(char board[][10] , int i , int j , int n)
    {
        for(int row=0 ; row<n ; row++)
        {
            if(board[row][j]=='Q')return false;
        }
        for(int col=0 ; col<n ; col++)
        {
            if(board[i][col]=='Q')return false;
        }
        int x=i;
        int y=j;
        while(x>=0 and y>=0)
        {
            if(board[x][y]=='Q')return false;
            x--;
            y--;
        }
        x=i;
        y=j;
        while(x>=0 and y<n)
        {
            if(board[x][y]=='Q')return false;
            x--;
            y++;
        }
        return true;
    }
    
    bool nqueen(char board[][10] , int i , int n , vector<vector<string>>&ans , string s , vector<string>&temp)
    {
        if(i==n)
        {
            temp.clear();
            
            for(int i=0 ; i<n ; i++)
            {
                for(int j=0 ; j<n ; j++)
                {
                    if(board[i][j]!='Q')board[i][j]='.';
                }
            }
            
            for(int i=0 ; i<n ; i++)
            {
                for(int j=0 ; j<n ; j++)
                {
                    s+=board[i][j];
                    
                    // temp.push_back(s);
                }
                temp.push_back(s);
                s.erase();
                // ans.push_back(temp);
                // temp.clear();
            }
            ans.push_back(temp);
            
            
            return false;
        }    
            
//             recusrive cade
            for(int j=0 ; j<n ; j++)
            {
                if(issafetoput(board , i , j , n))
                {
                    board[i][j]='Q';
                    bool kyabaatbni = nqueen(board , i+1 , n , ans , s , temp);
                    if(kyabaatbni)
                    {
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
            return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        char board[10][10];
        vector<vector<string>>ans;
        string s;
        vector<string>temp;
        
        nqueen(board , 0 , n , ans , s , temp);
        return ans;
    }
};