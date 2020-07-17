n elements
No of ways to partition in sets

bell(n) = Summation(S(n,k)) k=1 to n

bell(n,k) = no. of partition of set 1,2,....n+1 in which k+1 is the largest singleton element
https://www.youtube.com/watch?v=oGYFJ9gSBKw&list=PLEJXowNB4kPxQIN2dCUAnQ_92HIziG4x6&index=15

same formula

S(n+1,k) = k*S(n,k)+ S(n,k-1)

Bell Triangles

bell(5) using dp

so make bell[5][5]
if j==0
 bell[i][j] = bell[i-1][i-1]; //copying last element of previous row of the triangle ACHE SE DEKHO i-1 hai j-1 nhi
else
bell[i][j] = bell[i-1][j-1]+bell[i][j-1];