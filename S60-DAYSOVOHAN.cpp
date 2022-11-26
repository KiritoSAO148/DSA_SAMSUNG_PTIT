#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define ms(s,n) memset(s,n,sizeof(s))
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


ll solve (ll n, ll k){
	ll x = pow(2, n - 1);
	if (k == x) return n;
	if (k < x) return solve(n - 1, k);
	return solve(n - 1, k - x);
}

int main(){
    int t; scanf("%d", &t);
    while (t--){
    	ll n, k; scanf("%lld %lld", &n, &k);
    	printf("%lld\n", solve(n, k));
    }
    return 0;
}