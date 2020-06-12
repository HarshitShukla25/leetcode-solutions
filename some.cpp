class Solution {
public:
	 int N;
	vector<vector<string>> vv;
	bool isSafe(int board[N][N], int row, int col) 
	{ 
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
	} 
	bool solveNQueensutil(int board[N][N],int col)
	{
		if(col>=N)
		{	vector<string> v;
			for(int i=0;i<N;i++)
			{
				string k="";
				for(int j=0;j<N;j++)
				{
					if(board[i][j]==1)
						k=k+"Q";
					else
						k=k+".";
				}
				v.push_back(k);
			}

			vv.push_back(v);
			return true;
		}
		for(int i=0;i<N;i++)
		{
			if(isSafe(board,i,col))
			{
				board[i][col]=1;
				if(solveNQueensutil(board,col+1))
					return true;
				
				board[i][col]=0;
			}
		}
	}
    vector<vector<string>> solveNQueens(int n) {
    	N=n;
        int board[n][n];
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		board[i][j]=0;
        	}
        }
        if(solveNQueensutil(board,0)==false) return {};
        else
        {
        	return vv;
        }
    }
};