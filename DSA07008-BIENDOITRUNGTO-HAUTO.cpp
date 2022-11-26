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

int uutien (char c){
	if (c == '^') return 3;
	if (c == '*' || c == '/') return 2;
	if (c == '+' || c == '-') return 1;
	return 0;
}

void solve (string s){
	stack <char> st;
	string res = "";
	f0 (i,sz(s)){
		if (isalpha(s[i])) res += s[i];
		else if (s[i] == '(') st.push(s[i]);
		else if (s[i] == ')'){
			while (!st.empty() && st.top() != '('){
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while (!st.empty() && uutien(s[i]) <= uutien(st.top())){
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()){
		res += st.top();
		st.pop();
	}
	cout << res; el;
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	string s; cin >> s;
    	solve(s);
    }
    return 0;
}