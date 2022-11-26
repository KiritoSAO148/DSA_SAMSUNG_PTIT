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

int n, m, u, v;
vi adj[1001];
int visited[1001];
int par[1001];

void inp(){
	cin >> n >> m >> u >> v;
	f1 (i,n) adj[i].clear();
	ms(visited,0);
	f1 (i,n) par[i] = i;
	f0 (i,m){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
}

void bfs (int u){
	queue <int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x] = 1;
				par[x] = v;
			}
		}
	}
}

void path (int x, int y){
	bfs(x);
	if (!visited[y]){
		cout << "-1\n";
		return;
	}
	vi v;
	while (y != par[y]){
		v.pb(y);
		y = par[y];
	}
	v.pb(x);
	reverse(all(v));
	f0 (i,sz(v)){
		cout << v[i];
		if (i != sz(v) - 1) cout << " -> ";
		else el;
	}
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	inp();
    	path(u, v);
    }
    return 0;
}