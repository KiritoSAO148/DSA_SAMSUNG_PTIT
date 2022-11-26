#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++){
		int x=a[i], pos=i-1;
		while (pos>=0 && a[pos]>x){
			a[pos+1]=a[pos];
			--pos;
		}
		a[pos+1]=x;
		printf("Buoc %d: ", i);
		for (int j=0; j<=i; j++) printf("%d ", a[j]);
		printf("\n");
	}
	return 0;
}
