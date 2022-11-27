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
		for (int i=0; i<n; i++) cin >> a[i];
		stack<int>st;
		int ans=0;
		int i=0;
		while (i<n){
			if (st.empty() || a[i]>=a[st.top()]){
				st.push(i);
				++i;
			}else{
				int top=st.top(); st.pop();
				if (st.empty()){
					if (a[top]<=i) ans=max(ans,a[top]);
				}
				else if (a[top]<=(i-st.top()-1)) ans=max(ans,a[top]);
			}
		}
		while (!st.empty()){
			int top=st.top(); st.pop();
			if (st.empty()){
				if (a[top]<=i) ans=max(ans,a[top]);
			}
			else if (a[top]<=(i-st.top()-1)) ans=max(ans,a[top]);
		}
		cout << ans << "\n";
    }
    return 0;
}