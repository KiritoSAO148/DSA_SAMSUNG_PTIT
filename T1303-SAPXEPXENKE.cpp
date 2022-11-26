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

int cmp(const void *a, const void *b){
	return  *(int *)a-*(int *)b;
}

int main(){
    int t; scanf("%d", &t);
    while (t--){
    	int n; scanf("%d", &n);
    	int a[n];
    	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    	qsort(a, n, sizeof(int), cmp);
    	int l = 0, r = n - 1;
        while (l <= r){
            printf("%d %d ", a[r], a[l]);
            ++l; --r;
            if (l == r){
                printf("%d", a[l]); break;
            }
        }
        printf("\n");
    }
    return 0;
}