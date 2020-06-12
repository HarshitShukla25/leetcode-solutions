#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return the nth Fibonacci number 
int fib(int n) 
{ 
    double phi = (1 + sqrt(5)) / 2; 
    return round(pow(phi, n) / sqrt(5)); 
} 
  
// Function to return the required sum 
int calculateSum(int l, int r) 
{ 
  
    // Using our deduced result 
    int sum = fib(r + 2) - fib(l + 1); 
    return sum; 
} 
  
// Driver code 
int main() 
{ 
    int l = 4, r = 8; 
    cout << calculateSum(l, r); 
  
    return 0; 
} 

/* We can rewrite the relation F(n + 1) = F(n) + F(n – 1) as below:
F(n – 1) = F(n + 1) – F(n)
Similarly,
F(n – 2) = F(n) – F(n – 1)
…
…
…
F(0) = F(2) – F(1)

Adding all the equations, on left side, we have
F(0) + F(1) + … + F(n – 1) which is S(n – 1)

Therefore,
S(n – 1) = F(n + 1) – F(1)
S(n – 1) = F(n + 1) – 1
S(n) = F(n + 2) – 1

In order to find S(n), simply calculate the (n + 2)th Fibonacci number and subtract 1 from the result.
Therefore,
S(l, r) = S(r) – S(l – 1)
S(l, r) = F(r + 2) – 1 – (F(l + 1) – 1)
S(l, r) = F(r + 2) – F(l + 1) */