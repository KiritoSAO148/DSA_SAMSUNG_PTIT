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

ll powmod (ll n, ll k){
    if (k==0) return 1;
    ll x=powmod(n,k/2);
    if (k%2==0) return x*x%MOD;
    return n*(x*x%MOD)%MOD;
}

ll revn (ll n){
    ll tmp=0;
    while (n){
        tmp=tmp*10+n%10;
        n/=10;
    }
    return tmp;
}

int main(){
    int t; scanf("%d", &t);
    while (t--){
    	ll n; scanf("%lld", &n);
    	printf("%lld\n", powmod(n, revn(n)));
    }
    return 0;
}