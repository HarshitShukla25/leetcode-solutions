class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size(); 
        vector<int> B(n);
        
        for(int i=0;i<n;i++)
        {
            B[i]=-1*A[i];
        }
        int neg=kadane(B);
        int sum=0;
        for(int i=0;i<n;i++) sum+=A[i];
        
        int ans=max(kadane(A),sum+neg);
        if(ans==0) return kadane(A);
        return ans;
        
    }
    
    int kadane(vector<int> B)
    {
        int msf=INT_MIN,mef=0;
        
        for(int i=0;i<B.size();i++)
        {
            mef=max(B[i],mef+B[i]);
            msf=max(msf,mef);
        }
        
        return msf;
    }
};
/*
EXPLANATION:-
EX 1:-
   A = [1, -2, 3, -2]
   max = 3   (This means max subarray sum for normal array)
   min = -2  (This means min subarray sum for normal array)
   sum = 0   (total array sum)
   Maximum Sum = 3 (max)

EX2:-
  A = [5, -3, 5]
  max = 7
  min  = -3
  sum = 7
  maximum subarray sum = 7 - (-3) = 10
  
EX3:-
   A = [3, -1, 2, -1]
   max = 4
   min = -1
   sum = 3
   maximum subarray sum  = sum - min = 3 - (-1) = 4

EX4:-
   A = [-2, -3, -1]
   max = -1
   min = -6
   sum = -6
   In this example, if we do (sum - min) then result is 0. but there is no subarray with sum 0.
   So, in this case we return max value. that is -1.
   
From above examples, 
we can understand that 
maximum sum is either max (we get using kadane's algo) or (sum - min).
There is a special case, if sum == min,
then maximum sum is max.

Let's develop an algorithm to solve this problem.
1. Find maximum subarray sum using kadane's algorithm (max) 
2. Find minimum subarray sum using kadane's algorithm (min)
3. Find total sum of the array (sum)
4. Now, if sum == min return max
5. Otherwise, return maximum ( max, sum - min )
*/
/*The maximum subarray sum in circular array is maximum of following

Maximum subarray sum in non circular array
Maximum subarray sum in circular array.
Example - [1,2,5,-2,-3,5]
Steps -

Find the maximum subarray sum using Kadane Algorithm. This is maximum sum for non circular array.
image
1+2+5 = 8
For non circular sum,
Step 1) find the minimum subarray sum of array.
image
-2-3 =-5
Step 2) Now find the total sum of array = 1 + 2 + 5 -2 - 3 + 5 = 8
Step 3) The max subarray sum for circular array = Total Sum - Minimum subarray Sum
= 8 - (-5) = 8 + 5 =13
image
As illustrated above, substracting minimum subarray sum from total sum gives maximum circular subarray sum.
Answer = Max ( Non circular max sum + circular max sum )= max(8,13) = 13
Code -
The trick here is that to find the minimum subarray sum, we invert the sign of all the numbers in original subarray, and find the maximum subarray sum using Kadane algorithm. Then add it with the total sum. (which is similar to
[total - minimum subarray sum ])*/