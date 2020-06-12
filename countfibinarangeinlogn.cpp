#include <bits/stdc++.h> 
using namespace std; 
  
// Returns count of fibonacci numbers in [low, high] 
int countFibs(int low, int high) 
{ 
    // Initialize first three Fibonacci Numbers 
    int f1 = 0, f2 = 1, f3 = 1; 
  
    // Count fibonacci numbers in given range 
    int result = 0; 
  
    while (f1 <= high) 
    { 
        if (f1 >= low) 
           result++; 
        f1 = f2; 
        f2 = f3; 
        f3 = f1 + f2; 
    } 
  
    return result; 
} 

// this is an O(logn) algo go on gfg to find why?