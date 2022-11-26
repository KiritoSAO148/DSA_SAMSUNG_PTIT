#include <stdio.h>
#include <math.h>

int nt (int n){
	if (n<2) return 0;
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int tn (int n){
	int m=n;
	int tmp=0;
	while (m>0){
		tmp=tmp*10+m%10;
		m/=10;
	}
	if (tmp==n) return 1;
	else return 0;
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int a,b;
		scanf("%d %d", &a, &b);
		int cnt=0;
		for (int i=a; i<=b; i++){
			if (nt(i) && tn(i)){
				printf("%d ", i);
				++cnt;
				if (cnt==10){
					printf("\n");
					cnt=0;
				}
			}
		}
		printf("\n");
		printf("\n");
	}
	return 0;
}
