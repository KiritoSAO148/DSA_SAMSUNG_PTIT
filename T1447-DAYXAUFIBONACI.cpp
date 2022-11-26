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

ll f[93];

void fibo(){
    f[0]=0; f[1]=1;
    for (int i=2; i<=92; i++) f[i]=f[i-1]+f[i-2];
}

char solve (int n, ll k){
	if (n == 1) return 'A';
	if (n == 2) return 'B';
	if (k <= f[n - 2]) return solve(n - 2, k);
	return solve(n - 1, k - f[n - 2]);
}

int main(){
    int t; scanf("%d", &t);
    fibo();
    while (t--){
    	int n; scanf("%d", &n);
    	ll k; scanf("%lld", &k);
    	printf("%c\n", solve(n, k));
    }
    return 0;
}