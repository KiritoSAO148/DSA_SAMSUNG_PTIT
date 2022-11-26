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

int n, s, a[201], dp[40001];

int main(){
    int t; scanf("%d", &t);
    while (t--){
    	memset(dp, 0, sizeof(dp));
    	scanf("%d %d", &n, &s);
    	f1 (i,n) scanf("%d", &a[i]);
    	dp[0] = 1;
    	f0 (i,n){
    		for (int j = s; j >= a[i]; --j){
    			if (dp[j] == 0 && dp[j - a[i]] == 1) dp[j] = 1;
    		}
    	}
    	if (dp[s] == 1) printf("YES\n");
    	else printf("NO\n");
    }
    return 0;
}