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

int n, a[15], ok;

void init(){
	f1 (i,n) a[i] = 0;
}

void next(){
	int i = n;
	while (i >= 1 && a[i] == 1){
		a[i] = 0;
		--i;
	}
	if (i == 0) ok = 0;
	else a[i] = 1;
}

void gray(){
	cout << a[1];
	for (int i = 2; i <= n; ++i){
		if (a[i] == a[i - 1]) cout << 0;
		else cout << 1;
	}
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	cin >> n;
    	ok = 1;
    	init();
    	while (ok){
    		gray();
    		cout << ' ';
    		next();
    	}
    	el;
    }
    return 0;
}