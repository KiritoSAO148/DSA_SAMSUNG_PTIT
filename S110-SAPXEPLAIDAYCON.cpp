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
    	int a[n];
    	f0 (i,n) cin >> a[i];
    	int l = 0, r = 0;
    	for (int i = 0; i < n - 1; ++i){
    		if (a[i] > a[i + 1]){
    			l = i;
    			break;
    		}
    	}
    	for (int i = n - 1; i >= 1; --i){
    		if (a[i] < a[i - 1]){
    			r = i;
    			break;
    		}
    	}
    	int min = *min_element(a + l, a + r + 1);
    	int max = *max_element(a + l, a + r + 1);
    	for (int i = 0; i <= l; ++i){
    		if (a[i] > min){
    			l = i;
    			break;
    		}
    	}
    	for (int i = n - 1; i >= r; --i){
    		if (a[i] < max){
    			r = i;
    			break;
    		}
    	}
    	cout << l + 1 << ' ' << r + 1; el;
    }
    return 0;
}