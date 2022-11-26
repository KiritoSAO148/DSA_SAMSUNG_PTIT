#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	int t; scanf("%d", &t);
	while (t--){
		int a,b,c,d; scanf("%d %d %d %d", &a, &b, &c, &d);
		if (c-a==d-b) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
