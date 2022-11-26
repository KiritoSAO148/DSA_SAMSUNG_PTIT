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

int minSize (vvi &dp, int i, vi &a, int n, int sum){
	if (sum == 0) return 0;
	if (i == n) return -1;
	if (dp[i][sum] != 0) return dp[i][sum];
	int x, y, maxi;
	maxi = INT_MAX;
	x = y = maxi;
	if (a[i] <= sum){
		int m = minSize(dp, i + 1, a, n, sum - a[i]);
		if (m != -1) x = min(x, m + 1);
	}
	int m = minSize(dp, i + 1, a, n, sum);
	if (m != -1) y = min(y, m);
	return dp[i][sum] = (x == maxi && y == maxi) ? -1 : min(x,y);
}

int solve (vi &a, int sum, int n){
	vvi dp(n, vi(sum + 1, 0));
	return minSize(dp, 0, a, n, sum);
}

int main(){
    FileIO();
    FastIO;
    int n, s; cin >> n >> s;
    vi a(n);
    f0 (i,n) cin >> a[i];
    cout << solve(a, s, n);
    return 0;
}