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

int dx[2]={1,0};
int dy[2]={0,1};

int m, n, a[101][101], cnt;

void Try(int i, int j){
	if (i == n && j == m){
		++cnt;
		return;
	}
	for (int k = 0; k < 2; ++k){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) Try(i1, j1);
	}
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	cin >> n >> m;
    	f1 (i,n) f1 (j,m) cin >> a[i][j];
    	cnt = 0;
    	Try(1,1);
    	cout << cnt; el;
    }
    return 0;
}