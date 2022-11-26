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

int max (int a, int b){
    if (a>b) return a;
    return b;
}

int min (int a, int b){
    if (a<b) return a;
    return b;
}

int main(){
    int n; scanf("%d", &n);
    int a[n];
    f0 (i,n) scanf("%d", &a[i]);
    int dp[1001] = {0};
    int ma = -1000000000;
    f0 (i,n){
    	dp[i] = 1;
    	for (int j = 0; j < i; ++j){
    		if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
    	}
    	ma = max(ma, dp[i]);
    }
    printf("%d", ma);
    return 0;
}