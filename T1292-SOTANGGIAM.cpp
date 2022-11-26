#include <stdio.h>
#include <string.h>

int up (char c[], int n){
	for (int i = 0; i < n - 1; ++i){
		if ((c[i] - '0') > (c[i + 1] - '0')) return 0;
	}
	return 1;
}

int down (char c[], int n){
	for (int i = 0; i < n - 1; ++i){
		if ((c[i] - '0') < (c[i + 1] - '0')) return 0;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	getchar();
	while (t--){
		char c[501]; scanf("%s", &c);
		if (up(c, strlen(c)) || down(c, strlen(c))) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}