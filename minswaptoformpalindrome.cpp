#include <bits/stdc++.h> 
using namespace std; 
  
// Function that returns true if s1 
// and s2 are anagrams of each other 
bool isAnagram(string s1, string s2) 
{ 
    sort(s1.begin(), s1.end()); 
    sort(s2.begin(), s2.end()); 
    if (s1 == s2) 
        return 1; 
    return 0; 
} 
  
// Function to return the minimum swaps required 


int main() 
{ 
 
}
