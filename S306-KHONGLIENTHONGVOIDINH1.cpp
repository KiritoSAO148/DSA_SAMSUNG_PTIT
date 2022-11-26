#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TC() int t; cin >> t; while (t--)
#define el cout << "\n"
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn 

const int MOD = (int) 1e9+7;

void FileIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int n, m;
vi adj[301];
bool visited[301];

void dfs (int u){
	visited[u] = true;
	for (int v : adj[u]){
		if (!visited[v]) dfs(v);
	}
}

int main(){
    FileIO();
    FastIO;
    cin >> n >> m;
    f0 (i,m){
    	int x, y; cin >> x >> y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
    dfs(1);
    int ok = 0;
    f1 (i,n){
    	if (!visited[i]){
    		ok = 1;
    		cout << i << '\n';
    	}
    }
    if (!ok) cout << 0;
    return 0;
}