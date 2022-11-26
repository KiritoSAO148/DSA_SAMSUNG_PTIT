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

int prime[10001];

void sang(){
    for (int i=0; i<=10000; i++)
        prime[i]=1;
    prime[0]=prime[1]=0;
    for (int i=2; i<=sqrt(10000); i++){
        if (prime[i]){
            for (int j=i*i; j<=10000; j+=i)
                prime[j]=0;
        }
    }
}

bool used[10001];

int solve (int s, int t){
	queue <pii> q;
	used[s] = true;
	q.push({s, 0});
	while (!q.empty()){
		pii top = q.front(); q.pop();
		int tmp = top.fi;
		if (tmp == t) return top.se;
		int x = tmp;
		vi digit;
		while (x){
			digit.pb(x % 10);
			x /= 10;
		}
		reverse(all(digit));
		f0 (i,4){
			for (int j = 0; j <= 9; ++j){
				if (i == 0 && j == 0) continue;
				if (digit[i] != j){
					int new_num = 0;
					f0 (k,4){
						if (i != k) new_num = new_num * 10 + digit[k];
						else new_num = new_num * 10 + j;
					}
					if (!used[new_num] && prime[new_num]){
						used[new_num] = true;
						q.push({new_num, top.se + 1});
					}
				}
			}
		}
	}
	return -1;
}

int main(){
    FileIO();
    FastIO;
    sang();
    TC(){
    	int S, T; cin >> S >> T;
    	ms(used, false);
    	cout << solve(S, T); el;
    }
    return 0;
}