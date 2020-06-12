int maxsumsubarray(int arr[])
{
	int max_so_far =INT_MIN;
	int max_ending_here =0;
	for(int i=0;i<arr.size();i++)
	{
		max_ending_here = max_ending_here + a[i];
		if(max_ending_here < 0)
			max_ending_here =0; 
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
}

// another similar interpretation
int maxSubArraySum(int a[], int size) 
{ 
   int max_so_far = a[0]; 
   int curr_max = a[0]; 
  
   for (int i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
} 

// printing the subarray just maintain start and end
int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, 
       start =0, end = 0, s=0; 
  
    for (int i=0; i< size; i++ ) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    cout << "Maximum contiguous sum is "
        << max_so_far << endl; 
    cout << "Starting index "<< start 
        << endl << "Ending index "<< end << endl; 
} 

// ONE VARIATION OF THIS FREQUENTLY ASKED IS A MAXIMUM PRODUCT SUBARRAY, NOW U CANT IGNORE THE NEGATIVE ELEMENTS OR RATHER I SHOULD
// SAY THE MINIMUM ELEMENT SINCE WHEN MULTIPLIED BY A NEGATIVE NO> IT CAN BECOME A MAXIMUM ELEMENT SO CONSIDER THAT

int max_product_subarray (int arr[], int size)
{
	if(size==0) return 0;
	int max_product_here =1;
	int min_product_here =1;
	int res= 0;
	for(int i=0;i<size;i++)
	{
		max_product_here = max(max(max_product_here*a[i],min_product_here*a[i]),a[i]);
		max_product_here = min(min(max_product_here*a[i],min_product_here*a[i]),a[i]);
		if(max > res)
			res =max;

	}
	return res; 
}