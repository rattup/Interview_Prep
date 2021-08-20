class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        if(board[i][j]=='O')
        {
         board[i][j]='1';
        if(i>0)
        dfs(board,i-1,j);
        if(i<board.size()-1)
        dfs(board,i+1,j);
        if(j>0)
        dfs(board,i,j-1);
        if(j<board[i].size()-1)
        dfs(board,i,j+1);
            
        }
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        if(row==0)
        return;
        for(int i=0;i<row;i++)
        {
            dfs(board,i,0);
            dfs(board,i,col-1);
        }
        for(int j=0;j<col;j++)
        {
            dfs(board,0,j);
            dfs(board,row-1,j);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            if(board[i][j]=='O')
            board[i][j]='X';
            else if(board[i][j]=='1')
            board[i][j]='O';
        }
        
        
    }
};
