#include <bits/stdc++.h>
using namespace std;
int power(int a,unsigned int y,int p)
{   int res = 1;
    x = x % p;  // Update x if it is more than or 
                // equal to p
    while(y>0)
    {
        if( y & 1)
        res = (res*a) % p;
        y = y>>1;
        a=(a*a)%p;
    }
    return res;
}
bool millerTest(int d,int n)
{
    // Pick a random number in [2..n-2] 
    // Corner cases make sure that n > 4 
    int a = 2 + rand() % (n - 4); 
    int x = power(a,d,n);  //Compute a^d % n 
    if(x==1 || x== n-1)
    return true;
    // Keep squaring x while one of the following doesn't 
    // happen 
    // (i)   d does not reach n-1 
    // (ii)  (x^2) % n is not 1 
    // (iii) (x^2) % n is not n-1
    while(d!=n-1)
    {
        x = x*x % n;
        d*=2;
        if(x==1) return false;
        if(x==n-1) return true;
    }
    return false;
    
}
bool isPrime(int n,int k)
{
    if(n<=1 || n==4) return false;
    if(n<=3) return true;
    int d = n-1;
    while(d%2==0)
    d/=2;
    for (int i = 0; i < k; i++) 
         if (!millerTest(d, n))   //its actually a test for non-primalty
              return false; 
  
    return true;
}
int main()
{
    int k=5;
    for(int i=2;i<=100;i++)
    {
        if(isPrime(i,k))
        cout << i << " ";
    }
}