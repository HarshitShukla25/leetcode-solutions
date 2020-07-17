// Use case -
Count no. of possible BST with n keys.
Count no. of possible FBT with n+1 leaves.

C(0) = C(1) =1
 
c(2) = c0c1 +c1c0
c(3) = c0c2+c1c2+ c2c0
c(4) = c0c3+c1c2+c2c1+c3c0

c(n) = c0cn-1 +c1cn-2 +...............ci cn-i-1 + cn-1c0


result = 0 ;
for (i = 0 ; i <n; i++)
 result +=catalan(i) * catalan(n-i-1);

//Dp

c[0]=c[1]=1
for(int i = 2;i<= n; i++)
{	c[i]=0;
	for (int j =0;j<i;j++)
		c[i] += c[j]*c[i-j-1];

}
return c[n-1];