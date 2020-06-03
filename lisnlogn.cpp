int LongestIncreasingSubsequenceLength(std::vector<int>& v)  
{  
    if (v.size() == 0)  
        return 0;  
  
    std::vector<int> tail(v.size(), 0);  
    int length = 1; // always points empty slot in tail  
  
    tail[0] = v[0];  
      
    for (int i = 1; i < v.size(); i++) {  
  
            // Do binary search for the element in  
            // the range from begin to begin + length 
        auto b = tail.begin(), e = tail.begin() + length; 
        auto it = lower_bound(b, e, v[i]);  
              
        // If not present change the tail element to v[i]  
        if (it == tail.begin() + length) 
        tail[length++] = v[i];  
        else   
        *it = v[i];  
    }  
  
    return length;  
}  
//nlogn soln

int lis( int arr[], int n )  
{  
    int lis[n];  // only works for arrays not vector
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in  
       bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
}  
// n2 soln
