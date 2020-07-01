Let us first take an example to under the idea:
Suppose n = 4.
So we have elements - 1,2,3,4
There are total n!= 4! = 24 permutations possible. We can see a specific pattern here:

arr
[ 1            2           3          4]
1 2 3 4     2 1 3 4     3 1 2 4    4 1 2 3
1 2 4 3     2 1 4 3     3 1 4 2    4 1 3 2
1 3 2 4     2 3 1 4     3 2 1 4    4 2 1 3
1 3 4 2     2 3 4 1     3 2 4 1    4 2 3 1
1 4 2 3     2 4 1 3     3 4 1 2    4 3 1 2
1 4 3 2     2 4 3 1     3 4 2 1    4 3 2 1
So we have 4 block with 6 elements each.

n = 4  we can take an array [1,2,3,4] , initital ans = ""
lets say we have k =15, the 15 th permutation is "3 2 1 4":

As we can see the first value is 3 that means out of the four blocks we need the 3rd block. 
Each blocks has n-1! = 3! = 6 elements --> 15 = 6*2 + 3 i.e. we skip 2 blocks and our ans is the third element in the 3rd block
Let us assume the blocks are zero indexed.
Now 15 / 6 = 2;  So we select the 2nd block (0-indexed) that means 2nd index in our array - 3
Now ans = "3"
Remove this element from the array and our array becomes: [1,2,4]
---------------------------------------------------------------------------------------------
Now we are in this block:
3 1 2 4  - 1  
3 1 4 2  - 2   Block 0
  ------ 
3 2 1 4  - 3 (ans)
3 2 4 1  - 4    Block 1
  ------
3 4 1 2  - 5   
3 4 2 1  - 6    Block 2
Now we have 3 blocks each of with 2 elements 
i,e. n = n-1 = 3blocks and n-1! = 2! = 2 elements
n = 3, what will be the k? As we passed 12 elements we have k = 15-12 => the third element in this large block.
k = 3
element in partition (p) = 2;
k / p = 3 / 2 = 1 => ans is in block 1, value to add to ans  = 2
arr[1] = 2;
ans = "32"
remove 2 from array => [1,4]
Now we have 2 elements left(n-1 = 3-1) 
-----------------------------------------------------------------------------
32  1 4  Block 0
32  4 1  Block 1

n=2, k = 1
1 will be added ans = "321"  arr= [4]
As we only have one value value in array append it to ans.  ans = "3214"

One very important note:(Corner case)
When we have k as a multiple of elements in partition for e.g. k = 12 Then we want to be in block with index 1
but as index = 12 / 6 = 2; we have to keep index = index-1;
Only when we are aiming at the last element we will hit this case.
Here the blocks are zero indexed but the elements inside them are 1 index.

I'm sure after you look at the code you will completely understand it
Code:

class Solution {
public:
    // Our recursive function that will complete the ans string.
	// v - is our current array = [1,2,3,4]
	// ans is the answer string, n and k are current values of n and k
	// factVal is an array containing the factorial of all integers from 0-9 to get factorial in O(1) time.
	// That means I have stored all the factorials in this array before hand to avoid calculation. You can also write factorial funciton if you want.
	
    void setPerm(vector<int>& v,string& ans,int n,int k,vector<int>& factVal){
       // if there is only one element left append it to our ans (Base case)
	   if(n==1){
            ans+=to_string(v.back());
            return;
        }
		
		// We are calculating the required index.  factVal[n-1] means for n =  4 => factVal[3] = 6.
        // 15 / 6 = 2 will the index for k =15 and n = 4.
		int index = (k/factVal[n-1]);
        // if k is a multiple of elements of partition then decrement the index (Corner case I was talking about)
		if(k % factVal[n-1] == 0){
            index--;
        }
		
		ans+= to_string(v[index]);  // add value to string
        v.erase(v.begin() + index);  // remove element from array
        k -= factVal[n-1] * index;   // adjust value of k; k = 15 - 6*2 = 3.
		// Recursive call with n=n-1 as one element is added we need remaing.
        setPerm(v,ans,n-1,k,factVal);
    }
    
    string getPermutation(int n, int k) {
        if(n==1) return "1";
		//Factorials of 0-9 stored in the array. factVal[3] = 6. (3! = 6)
        vector<int>factVal = {1,1,2,6,24,120,720,5040,40320,362880};
        string ans = "";
        vector<int> v;
		// Fill the array with all elements
        for(int i=1;i<=n;i++) v.emplace_back(i);
        setPerm(v,ans,n,k,factVal);
        return ans;
    }
};


//Easy C++ hack
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> myints;
        for(int i=1;i<=n;i++)
            myints.push_back(i);
        k=k-1;
        while(k--)
        {
            next_permutation(myints.begin(),myints.end());
        }  
        string ans="";
        for(auto &ch : myints)
            ans=ans+to_string(ch);
    return ans;
    }
};