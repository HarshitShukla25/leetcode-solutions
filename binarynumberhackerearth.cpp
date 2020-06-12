#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll tt[50];
void pre(){
    tt[0]=1;
    tt[1]=2;
    for(int i=2;i<40;i++) {
        tt[i]=tt[i-1]+tt[i-2];
    }
}
string FindIt(int n){
    string ans="";
    for(int i=10;i>=0;i--){
        cout << n<<" " <<tt[i] << " ";
        if(tt[i]<=n){
            n-=tt[i];
            if(tt[i]==0){
                ans+="0";
            } else if(tt[i]==1){
                ans+="1";
            } else {
                ans+="10";
                i--;
            }
        } else {
            ans+="0";
        }
        cout << ans << endl;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("finaloutput.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string ans=FindIt(n);
        bool flag=false;
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='1') { cout<<ans[i]; flag=true; }
            else if(flag) cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}