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

char c[100001];

int main(){
    scanf("%s", c);
    int pos = 0, n = strlen(c);
    while (pos < n){
    	char tmp = c[pos];
    	int last_pos = pos;
    	for (int i = pos; i < n; ++i){
    		if (tmp < c[i]) tmp = c[i];
    	}
    	for (int i = pos; i < n; ++i){
    		if (c[i] == tmp){
    			printf("%c", c[i]);
    			last_pos = i;
    		}
    	}
    	pos = last_pos + 1;
    }
    return 0;
}