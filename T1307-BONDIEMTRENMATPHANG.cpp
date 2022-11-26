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

struct point{
	int x, y, z;
};

point mul (point a, point b){
	point res;
	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return res;
}

bool check (point a, point b, point c, point d){
	point ab;
	ab.x = b.x - a.x, ab.y = b.y - a.y, ab.z = b.z - a.z;
	point ac;
	ac.x = c.x - a.x, ac.y = c.y - a.y, ac.z = c.z - a.z;
	point ad;
	ad.x = d.x - a.x, ad.y = d.y - a.y, ad.z = d.z - a.z;
	point res = mul(ab, ac);
	return (ad.x * res.x + ad.y * res.y + ad.z * res.z) == 0;
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	point a, b, c, d;
    	cin >> a.x >> a.y >> a.z;
    	cin >> b.x >> b.y >> b.z;
    	cin >> c.x >> c.y >> c.z;
    	cin >> d.x >> d.y >> d.z;
    	if (check(a, b, c, d)) cout << "YES\n";
    	else cout << "NO\n";
    }
    return 0;
}