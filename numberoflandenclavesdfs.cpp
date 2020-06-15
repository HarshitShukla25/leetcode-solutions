class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>& board)
    {
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1) return ;
        if(board[i][j]==2 || board[i][j]==0)
            return ;
        board[i][j]=2;
        dfs(i+1,j,board);
         dfs(i-1,j,board);
         dfs(i,j+1,board);
         dfs(i,j-1,board);
    }
    int numEnclaves(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
            {
                if((i==0 || j==0 || i==A.size()-1 || j==A[0].size()-1)&&(A[i][j]==1))
                    dfs(i,j,A);            }
        }
        int count=0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
            {
                if(A[i][j]==1)
                    count++;
                }
        }
        return count;
    }
};