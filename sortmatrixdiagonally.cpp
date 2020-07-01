class Solution {
public:
vector<vector> diagonalSort(vector<vector>& mat) {
int n=mat.size();
if(n==0)
return {};
int m=mat[0].size();
map<int,multiset > mp;
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
mp[i-j].insert(mat[i][j]);
}
}

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      mat[i][j]=*mp[i-j].begin();
      mp[i-j].erase(mp[i-j].begin());
    }
  }
  return mat;
}
};