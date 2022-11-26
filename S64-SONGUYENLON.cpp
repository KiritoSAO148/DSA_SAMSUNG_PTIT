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

string s1, s2;
int dp[1001][1001];

int main(){
    FileIO();
    FastIO;
    TC(){
    	cin >> s1 >> s2;
    	ms(dp, 0);
    	int n = sz(s1), m = sz(s2);
    	s1 = " " + s1; s2 = " " + s2;
    	f1 (i,n){
    		f1 (j,m){
    			if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
    			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    		}
    	}
    	cout << dp[n][m]; el;
    }
    return 0;
}