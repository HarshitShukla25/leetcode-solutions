class Solution {
    class myComparator 
{ 
public: 
    int operator() (const pair<int,pair<int,int>>& p1, const pair<int,pair<int,int>>& p2) 
    { 
        return p1.first > p2.first; 
    } 
}; 
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,myComparator> pq;
        vector<int> dis(n);
        for(int i=0;i<n;i++)
        {
            dis[i] = (points[i][0])*(points[i][0])+(points[i][1])*(points[i][1]);
             pq.push({dis[i],{(points[i][0]),(points[i][1])}});
        }
        vector<vector<int>> res(K);
        pair<int,int> p;
       for(int i=0;i<K;i++)
       {
          p =pq.top().second;
           res[i] = {p.first,p.second};
           pq.pop();
       }
        return res;
    }
    
};