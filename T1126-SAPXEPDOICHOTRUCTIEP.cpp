#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//#define ll long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	int n; scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (a[i]>a[j]){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
		printf("Buoc %d: ", i+1);
		for (int j=0; j<n; j++) printf("%d ", a[j]);
		printf("\n");
	}
	return 0;
}
