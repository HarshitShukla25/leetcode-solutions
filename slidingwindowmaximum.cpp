 vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ans;
    if (k == 0) return ans;
    multiset<int>s(nums.begin(), nums.begin() + k);
    auto mid = next(s.begin(), (k - 1) / 2);
    if(k%2!=0)
    {
        ans.push_back(*(mid)/1.0);
    }
    else
    {
        ans.push_back(((*mid)/1.0 + *next(mid, (k + 1) % 2)) / 2.0);
    }
    for (int i = k; i < nums.size(); ++i) 
    { 
      s.erase(s.lower_bound(nums[i - k])); 
      s.insert(nums[i]);
      mid = next(s.begin(), (k - 1) / 2);
      if(k%2!=0)
     {
        ans.push_back(*(mid)/1.0);
     }
     else
     {
        ans.push_back(((*mid)/1.0 + *next(mid, (k + 1) % 2)) / 2.0);
     }
    }
    return ans;
    }