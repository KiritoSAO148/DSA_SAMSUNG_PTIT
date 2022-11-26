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

int main(){
    FileIO();
    FastIO;
    TC(){
    	int n; cin >> n;
    	vi a(n);
    	int dp1[n], dp2[n];
    	ms(dp1,0);
    	ms(dp2,0);
    	f0 (i,n) cin >> a[i];
    	f0 (i,n){
    		dp1[i] = a[i];
    		f0 (j,i){
    			if (a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + a[i]);
    		}
    	}
    	for (int i = n - 1; i >= 0; --i){
    		dp2[i] = a[i];
    		for (int j = n - 1; j > i; --j){
    			if (a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + a[i]);
    		}
    	}
    	int ans = INT_MIN;
    	f0 (i,n) ans = max(ans, dp1[i] + dp2[i] - a[i]);
    	cout << ans; el;
    }
    return 0;
}