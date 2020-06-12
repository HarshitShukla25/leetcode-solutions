#include <bits/stdc++.h>
using namespace std;
int lis(int arr[],int n)
{
	int lis[n];
	lis[0]=1;
	for(int i=1;i<n;i++)
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && lis[i] < lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}
	return *max_element(lis, lis+n);
}
//Printing an LIS sequence
void constructPrintLIS(int arr[], int n) 
{ 
    // L[i] - The longest increasing sub-sequence  
    // ends with arr[i] 
    vector<vector<int> > L(n); 
  
    // L[0] is equal to arr[0] 
    L[0].push_back(arr[0]); 
  
    // start from index 1 
    for (int i = 1; i < n; i++) 
    { 
        // do for every j less than i 
        for (int j = 0; j < i; j++) 
        { 
            /* L[i] = {Max(L[j])} + arr[i] 
            where j < i and arr[j] < arr[i] */
            if ((arr[i] > arr[j]) && 
                    (L[i].size() < L[j].size() + 1)) 
                L[i] = L[j]; 
        } 
  
        // L[i] ends with arr[i] 
        L[i].push_back(arr[i]); 
    } 
  
    // L[i] now stores increasing sub-sequence of 
    // arr[0..i] that ends with arr[i] 
    vector<int> max = L[0]; 
  
    // LIS will be max of all increasing sub- 
    // sequences of arr 

   
    for (vector<int> x : L)            //THiS YOU COULDNT HAVE WRITTEN IT BY YOURSELf
        if (x.size() > max.size()) 
            max = x; 
  
    // max will contain LIS 
    printLIS(max); 
} 
int main()
{
 	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Length of lis is %d\n", lis( arr, n ) );  
    return 0; 
}