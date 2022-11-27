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

int n, k, a[10], ok;
vector <string> v;
int ans;

void next(){
	int i = k - 1;
	while (i >= 1 && a[i] > a[i + 1]) --i;
	if (i == 0) ok = false;
	else {
		int j = k;
		while (a[i] > a[j]) --j;
		swap(a[i], a[j]);
		f0 (h,n) swap(v[h][i - 1], v[h][j - 1]);
		reverse(a + i + 1, a + k + 1);
		f0 (h,n) reverse(v[h].begin() + i, v[h].end());
	}
}

int main(){
    FileIO();
    FastIO;
    cin >> n >> k;
    v.resize(n);
    for (auto &x : v) cin >> x;
    f1 (i,k) a[i] = i;
    ok = true;
    ans = INT_MAX;
    while (ok){
    	vector <string> s = v;
    	sort(all(s));
    	ans = min(ans, stoi(s[n - 1]) - stoi(s[0]));
    	next();
    }
    cout << ans;
    return 0;
}