#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int n,p,s,X[100];
vector <int> nto;
vector<vector<int>> res;

int prime[201];

void sang(){
    for (int i=0; i<=200; i++)
        prime[i]=1;
    prime[0]=prime[1]=0;
    for (int i=2; i<=sqrt(200); i++){
        if (prime[i]){
            for (int j=i*i; j<=200; j+=i)
                prime[j]=0;
        }
    }
}

void ktao(){
	cin >> n >> p >> s;
	nto.clear();
	res.clear();
	for (int i=p+1; i<=s; i++){
		if (prime[i]){
			nto.pb(i);
		}
	}
}

void Try(int i, int pos, int sum){
	if (i==n && sum==s){
		vector<int> tmp(X,X+n);
		res.pb(tmp);
	}
	for (int j=pos; j<nto.size(); j++){
		if (sum+nto[j]<=s){
			X[i]=nto[j];
			Try(i+1,j+1,sum+nto[j]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while (t--){
		ktao();
		Try(0,0,0);
		cout << res.size() << endl;
		for (auto it : res){
			for (int x : it){
				cout << x << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
