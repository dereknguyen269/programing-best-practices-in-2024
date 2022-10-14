//https://www.codechef.com/submit/B01T
#include <bits/stdc++.h>
using namespace std;
#define mod (ll)(998244353)
#define pii pair<ll,ll>
#define vi vector<ll>
// #define v vector
#define vc vector<char>
#define vvi vector<vector<int>>
#define vpii vector< pii >
#define vvpii vector<vector< pair<ll,ll> >>
#define f first
#define s second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define print(vec, l, r)                                                       \
    for (int i = l; i <= r; i++)                                               \
        cout << vec[i] << " ";                                                 \
    cout << endl;
#define forf(i, a, b) for (ll i = (a); i < (b); i++)
#define forr(i, a, b) for (ll i = (a); i > (b); i -= 1)
#define input(vec, N) for (int i = 0; i < (N); i++) cin >> vec[i];                                            
typedef long long ll;
#define ld long double
const int N = (2e5+20);
const int M = (1e6+20);
const int MAXN = 2e6+12;
const ll INF = 2e18+90;
#define BLOCK 555
 
typedef unsigned long long ull;
typedef long double lld;
 
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required
// using namespace __gnu_pbds; //required 
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 

// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k



long long binpow(long long a, long long b, long long m = mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

#define no cout<<"NO"<<endl;return;
#define yes cout<<"YES"<<endl;return;




// file open close
void solve(int tte){

    int n;
    cin>>n;

    int a[n+2];
    forf(i,1,n+1) cin>>a[i];

    vvi adj(n+2);

    queue < int > q;
    vi deg(n+2,0);

    forf(i,1,n){
      int u,v;
      cin>>u>>v;

      adj[u].pb(v);
      adj[v].pb(u);
      deg[u]++;
      deg[v]++;
    }

    int rem = 0;

    forf(i,1,n+1){
      if(a[i]) rem++;
      else rem--;

      if(adj[i].size() == 1 && i>1){
        q.push(i);
      }
    }

    vi mark(n+2,0);
    set < int > s;

    while(q.size()){

      if(!rem) break;

      int v = q.front();
      //cout<<v<<endl;
      q.pop();
      s.insert(v);

      if(a[v]){
        rem-=2;
      }else{
        rem+=2;
      }

      for(auto x : adj[v]){
        s.erase(x);
        deg[x]--;
        if(x>1 && deg[x]==1){
          q.push(x);
        }
      }

    }

    cout<<s.size()<<endl;

    for(auto x : s){
      cout<<x<<" ";
    }
    cout<<endl;


    

    


}
// file open close

signed main() {
  #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  
  cin >> T;
  int t=1;
  // bfs();
  // calc();
  // sieve(N-5);
  // calc();
  while (t<=T) {
      //cout<<"Case #"<<t<<": ";
      solve(t);
      t++;
  }
}