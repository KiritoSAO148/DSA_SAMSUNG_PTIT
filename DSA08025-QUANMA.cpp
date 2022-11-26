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

int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

int si, sj, ti, tj;
int d[10][10];
bool visited[10][10];

int bfs (int i, int j){
	queue <pii> q;
	q.push({i, j});
	d[i][j] = 0;
	visited[i][j] = true;
	while (!q.empty()){
		pii top = q.front(); q.pop();
		int i = top.fi, j = top.se;
		if (i == ti && j == tj) return d[i][j];
		f0 (k, 8){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if (i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && !visited[i1][j1]){
				d[i1][j1] = d[i][j] + 1;
				visited[i1][j1] = true;
				q.push({i1, j1});
			}
		}
	}
	return -1;
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	string s; cin >> s;
    	si = s[1] - '0';
    	sj = (s[0] - 'a') + 1;
    	string t; cin >> t;
    	ti = t[1] - '0';
    	tj = (t[0] - 'a') + 1;
    	ms(d, 0);
    	ms(visited, false);
    	cout << bfs(si, sj); el;
    }
    return 0;
}