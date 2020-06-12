#include <bits/stdc++.h>
using namespace std;
#define N 8
int isSafe(int x, int y, int sol[N][N]) 
{ 
    return ( x >= 0 && x < N && y >= 0 && 
             y < N && sol[x][y] == -1); 
} 
  
/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N]) 
{ 
    for (int x = 0; x < N; x++) 
    { 
        for (int y = 0; y < N; y++) 
            printf(" %2d ", sol[x][y]); 
        printf("\n"); 
    } 
} 
int solveKTutil(int x,int y,int movei,int sol[N][N],int xMove[N],int yMove[N])
{
	int k,next_x,next_y;
	if(movei==N*N)
		return 1;
	for(k=0;k<8;k++)  //all 8 moves
	{
		next_x = x+ xMove[i];
		next_y = y+ yMove[i];
		if(isSafe(next_x,next_y,sol))
		{
			sol[next_x][next_y] = movei;
			if(solveKTutil(next_x,next_y,movei+1,sol,xMove,yMove)==1)
			{
				return 1;
			}
			else
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}





int solvekt()
{
	int sol[N][N];
	forn(i,N) forn(j,N) sol[i][j]=-1;
	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
    sol[0][0]=0;
    if(solveKTutil(0,0,1,sol,xMove,yMove)==0)
    	{printf("The solution does not exist");return 0;}
    else
    	printsolution(sol);
}






int main(){
	solvekt();
	return 0;
}