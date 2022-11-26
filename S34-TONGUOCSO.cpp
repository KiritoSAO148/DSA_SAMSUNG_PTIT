#include <stdio.h>

#define maxn 1000000

int p[maxn + 1];

void init(){
	for (int i = 1; i <= maxn; ++i) p[i] = 0;
	for (int i = 1; i <= maxn; ++i){
		for (int j = 1; j <= maxn / i; ++j)
			p[j * i] += i;
	}
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	init();
	int a,b; scanf("%d %d", &a, &b);
	int cnt = 0;
	for (int i = a; i <= b; ++i){
		if (p[i] - i > i) ++cnt;
	}
	printf("%d", cnt);
	return 0;
}
