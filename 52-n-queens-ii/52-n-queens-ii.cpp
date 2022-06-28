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
    
    bool nqueen(char board[][10] , int i , int n , int&count)
    {
        if(i==n)
        {
           count++;
            return false;
        }    
            
//             recusrive cade
            for(int j=0 ; j<n ; j++)
            {
                if(issafetoput(board , i , j , n))
                {
                    board[i][j]='Q';
                    bool kyabaatbni = nqueen(board , i+1 , n , count);
                    if(kyabaatbni)
                    {
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
            return false;
    }
    
    int totalNQueens(int n) {
        
        char board[10][10];
        // vector<vector<string>>ans;
        // string s;
        // vector<string>temp;
        int count=0;
        
        nqueen(board , 0 , n , count);
        return count;
        
    }
};