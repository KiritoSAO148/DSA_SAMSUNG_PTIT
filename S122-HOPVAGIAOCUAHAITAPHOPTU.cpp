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
    string s1, s2; getline(cin, s1); getline(cin, s2);
    f0 (i, sz(s1)) s1[i] = tolower(s1[i]);
    f0 (i,sz(s2)) s2[i] = tolower(s2[i]);
    map <string, int> mp;
    set <string> s;
    stringstream ss(s1);
    string token;
    while (ss >> token){
    	s.insert(token);
    	mp[token] = 1;
    }
    stringstream sss(s2);
    while (sss >> token){
    	s.insert(token);
    	if (mp[token] == 1) mp[token] = 2;
    }
    for (string x : s) cout << x << ' ';
    el;
	for (auto it : mp){
		if (it.se == 2) cout << it.fi << ' ';
	}
    return 0;
}