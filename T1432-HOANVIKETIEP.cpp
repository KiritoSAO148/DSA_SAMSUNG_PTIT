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

void swap (int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int n, a[1001];

void rev (int a[], int l, int r){
	while (l <= r){
		swap(&a[l], &a[r]);
		++l; --r;
	}
}

void next(){
	int i = n - 1;
	while (i >= 1 && a[i] > a[i + 1]) --i;
	if (i == 0){
		f1 (i,n) a[i] = i;
	}else{
		int j = n;
		while (a[i] > a[j]);
		swap(&a[i], &a[j]);
		rev(a, i + 1, n - 1);
	}
}

int main(){
    int t; scanf("%d", &t);
    while (t--){
    	scanf("%d", &n);
    	f1 (i,n) scanf("%d", &a[i]);
    	next();
    	f1 (i,n) printf("%d ", a[i]);
    	printf("\n");
    }
    return 0;
}