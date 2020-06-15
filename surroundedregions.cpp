class Solution {
public:
    void dfs(int i,int j, vector<vector<char>>& board)
    {
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1) return ;
        if(board[i][j]=='V' || board[i][j]=='X')
            return ;
        board[i][j]='V';
        dfs(i+1,j,board);
         dfs(i-1,j,board);
         dfs(i,j+1,board);
         dfs(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if((i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1)&&(board[i][j]=='O'))
                    dfs(i,j,board);            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='V')
                    board[i][j]='O';
                else
                    board[i][j]='X';
                }
        }
        
    }
           
};