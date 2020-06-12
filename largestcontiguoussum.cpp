An efficient solution is based on the fact that all elements are positive. So we consider longest increasing subarrays and compare their sums. To increasing subarrays cannot overlap, so our time complexity becomes O(n).

Algorithm:

Let arr be the array of size n
Let result be the required sum

int largestSum(arr, n) 
    result = INT_MIN  // Initialize result

    i = 0
    while i < n

        // Find sum of longest increasing subarray
        // starting with i
        curr_sum = arr[i];
    while i+1 < n && arr[i] < arr[i+1]
              curr_sum += arr[i+1];
          i++; 

        // If current sum is greater than current
        // result.
        if result < curr_sum
            result = curr_sum; 

        i++;
    return result
Below is the implementation of above algorithm.

filter_none
edit
play_arrow

brightness_4
// C++ implementation of largest sum 
// contiguous increasing subarray 
#include <bits/stdc++.h> 
using namespace std; 
  
// Returns sum of longest 
// increasing subarray. 
int largestSum(int arr[], int n) 
{ 
    // Initialize result 
    int result = INT_MIN; 
  
    // Note that i is incremented 
    // by inner loop also, so overall 
    // time complexity is O(n) 
    for (int i = 0; i < n; i++) 
    { 
        // Find sum of longest  
        // increasing subarray  
        // starting from arr[i] 
        int curr_sum = arr[i]; 
        while (i + 1 < n &&  
               arr[i + 1] > arr[i]) 
        { 
            curr_sum += arr[i + 1]; 
            i++; 
        } 
  
        // Update result if required 
        if (curr_sum > result) 
            result = curr_sum; 
    } 
  
    // required largest sum 
    return result; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = {1, 1, 4, 7, 3, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Largest sum = " 
         << largestSum(arr, n); 
    return 0; 
} 