#include <bits/stdc++.h>

#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long int
#define ull         unsigned long long int
#define pb          push_back
#define endl        '\n'
#define piil         pair<ll ,ll >
#define vi          vector<ll>
#define vpi         vector<pair<ll,ll>>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
using namespace std;
ll fact(ll n) 
{
    return (n==1 || n==0) ? 1: n * fact(n - 1);  
} 

ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
class BST 
{ 
    int data; 
    BST *left, *right; 
  
    public: 
      
    // Default constructor. 
    BST(); 
      
    // Parameterized constructor. 
    BST(int); 
      
    // Insert function. 
    BST* Insert(BST *, int,BST *); 
    BST* findParent(BST* node, int val, BST* parent);
      
    // Inorder traversal. 
    void Inorder(BST *); 
}; 
  
// Default Constructor definition. 
BST :: BST() : data(0), left(NULL), right(NULL){} 
  
// Parameterized Constructor definition. 
BST :: BST(int value) 
{ 
    data = value; 
    left = right = NULL; 
} 

BST* BST :: findParent(BST* node, int val, BST* parent) 
{ 
    if (node == NULL) 
        return NULL; 
  
    // If current node is the required node 
    if (node->data == val) { 
  
        // Print its parent 
        return parent;
    } 
    else { 
  
        // Recursive calls for the children 
        // of the current node 
        // Current node is now the new parent 
        findParent(node->left, val, node); 
        findParent(node->right, val, node); 
    } 
    return NULL;
}   
// Insert function definition. 
BST* BST :: Insert(BST *root, int value,BST *temp) 
{ 
    if(!root) 
    { 
        // Insert the first node, if root is NULL. 
        return new BST(value); 
    } 
    if(value == findParent(root,value,temp)->data)
    {
        return findParent(root,value,temp);
    }
    // Insert data. 
    if(value > root->data) 
    { 
        // Insert right node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 
          
        // Process right nodes. 
        root->right = Insert(root->right, value,temp); 
    } 
    else
    { 
        // Insert left node data, if the 'value'  
        // to be inserted is greater than 'root' node data. 
          
        // Process left nodes. 
        root->left = Insert(root->left, value,temp); 
    } 
      
    // Return 'root' node, after insertion. 
    return root; 
} 
  
// Inorder traversal function. 
// This gives data in sorted order. 
void BST :: Inorder(BST *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    Inorder(root->left); 
    cout << root->data << endl; 
    Inorder(root->right); 
} 
  
// Driver code 
int main() 
{  io
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--)
    {   BST b, *root = NULL; 

        string k;
        cin >> k;
        
        BST *temp =root;
        root = b.Insert(root,int(k[0]),temp);
        for(int i=1;i<k.size();i++)
        {
            
             b.Insert(root,int(k[i]),temp);
        }
        b.Inorder(root); 
    }
    
    return 0; 
} 
  
// This code is contributed by pkthapa 


---------------------
#include <bits/stdc++.h>

#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long int
#define ull         unsigned long long int
#define pb          push_back
#define endl        '\n'
#define piil         pair<ll ,ll >
#define vi          vector<ll>
#define vpi         vector<pair<ll,ll>>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
using namespace std;
ll fact(ll n) 
{
    return (n==1 || n==0) ? 1: n * fact(n - 1);  
} 

ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
class BST 
{ 
    int data; 
    BST *left, *right; 
  
    public: 
      
    // Default constructor. 
    BST(); 
      
    // Parameterized constructor. 
    BST(int); 
      
    // Insert function. 
    BST* Insert(BST *, int,BST *); 
    BST* findParent(BST* node, int val, BST* parent);
      
    // Inorder traversal. 
    void Inorder(BST *); 
}; 
  
// Default Constructor definition. 
BST :: BST() : data(0), left(NULL), right(NULL){} 
  
// Parameterized Constructor definition. 
BST :: BST(int value) 
{ 
    data = value; 
    left = right = NULL; 
} 

BST* BST :: findParent(BST* node, int val, BST* parent) 
{ 
    if (node == NULL) 
        return NULL; 
  
    // If current node is the required node 
    if (node->data == val) { 
  
        // Print its parent 
        return parent;
    } 
    else { 
  
        // Recursive calls for the children 
        // of the current node 
        // Current node is now the new parent 
        findParent(node->left, val, node); 
        findParent(node->right, val, node); 
    } 
    return NULL;
}   
// Insert function definition. 
BST* BST :: Insert(BST *root, int value,BST *temp) 
{ 
    if(!root) 
    { 
        // Insert the first node, if root is NULL. 
        return new BST(value); 
    } 
    if(value == findParent(root,value,temp)->data)
    {
        return findParent(root,value,temp);
    }
    // Insert data. 
    if(value > root->data) 
    { 
        // Insert right node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 
          
        // Process right nodes. 
        root->right = Insert(root->right, value,temp); 
    } 
    else
    { 
        // Insert left node data, if the 'value'  
        // to be inserted is greater than 'root' node data. 
          
        // Process left nodes. 
        root->left = Insert(root->left, value,temp); 
    } 
      
    // Return 'root' node, after insertion. 
    return root; 
} 
  
// Inorder traversal function. 
// This gives data in sorted order. 
void BST :: Inorder(BST *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    Inorder(root->left); 
    cout << root->data << endl; 
    Inorder(root->right); 
} 
  
// Driver code 
int main() 
{  io
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--)
    {   BST b, *root = NULL; 

        string k;
        cin >> k;
        
        BST *temp =root;
        root = b.Insert(root,int(k[0]),temp);
        for(int i=1;i<k.size();i++)
        {
            
             b.Insert(root,int(k[i]),temp);
        }
        b.Inorder(root); 
    }
    
    return 0; 
} 
  
// This code is contributed by pkthapa 


---------------------
#include <bits/stdc++.h>
using namespace std; 
int v[200000];
int f[200000];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        f[i]=i;
    }
    while(m--){
        int p,q;
        scanf("%d%d",&p,&q);
        f[find(p)]=find(q);
    }
    for(int i=1;i<=n;i++){
        f[i] = find(i);
        v[f[i]]=min(v[f[i]],v[i]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++) if(f[i]==i){
        ans+=v[i];
    }
    cout << ans << endl;
    return 0;
}