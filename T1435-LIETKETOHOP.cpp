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

int n, k, a[1001], ok;

void init(){
	f1 (i,n) a[i] = i;
}

void next(){
	int i = k;
	while (i >= 1 && a[i] == n - k + i) --i;
	if (i == 0){
		ok = 0;
	}else{
		++a[i];
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
}

int main(){
    int t; scanf("%d", &t);
    while (t--){
    	scanf("%d %d", &n, &k);
    	init();
    	ok = 1;
    	while (ok){
    		f1 (i,k) printf("%d", a[i]);
    		printf(" ");
    		next();
    	}
    	printf("\n");
    }
    return 0;
}