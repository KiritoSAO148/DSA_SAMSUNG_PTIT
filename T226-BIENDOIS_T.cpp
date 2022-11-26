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

int tinh(int s, int t){
	queue<pii>q;
	set<int>se1;
	q.push({s,0});
	while (!q.empty()){
		pii top = q.front(); q.pop();
		if (top.first==t) return top.second;
		if (top.first-1==t || top.first*2==t) return top.second+1;
		se1.insert(top.first);
		if (top.first>=1 && !se1.count(top.first-1)) q.push({top.first-1,top.second+1});
		if (top.first<t && !se1.count(top.first*2)) q.push({top.first*2,top.second+1});
	}
	return 0;
}

int main(){
	FastIO;
	FileIO();
	int t; cin >> t;
	while (t--){
		int s,t; cin >> s >> t;
		cout << tinh(s,t) << endl;
	}
	return 0;
}