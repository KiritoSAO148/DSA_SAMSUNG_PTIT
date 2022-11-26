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

int n, x[20], ans;
string s;

bool check (ll n){
	int x = cbrt(n) + 0.5;
	return 1ll * x * x * x == n;
}

void Try (int i){
	for (int j = 0; j <= 1; ++j){
		x[i] = j;
		if (i == n - 1){
			ll tmp = 0;
			f0 (k,n){
				if (x[k]){
					tmp = tmp * 10 + s[k] - '0';
				}
			}
			if (check(tmp) && ans < tmp) ans = tmp;
		}
		else Try(i + 1);
	}
}

int main(){
    FileIO();
    FastIO;
    int t; cin >> t;
    while (t--){
    	cin >> s;
    	n = sz(s);
    	ans = 0;
    	Try(0);
    	if (ans == 0) cout << -1;
    	else cout << ans;
    	el;
    }
    return 0;
}