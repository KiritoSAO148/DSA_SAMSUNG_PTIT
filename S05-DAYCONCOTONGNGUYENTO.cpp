#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define maxn 500

int p[maxn + 1];

void init(){
	for (int i = 1; i <= maxn; ++i) p[i] = 1;
	p[0] = p[1] = 0;
	for (int i = 2; i <= sqrt(maxn); ++i){
		if (p[i]){
			for (int j = i * i; j <= maxn; j += i) p[j] = 0;
		}
	}
}

//int prime (int n){
//	if (n < 2) return 0;
//	for (int i = 2; i <= sqrt(n); ++i){
//		if (n % i == 0) return 0;
//	}
//	return 1;
//}

int n, a[20], x[20];
vector <vector<int>> v;

bool cmp (int a, int b){
	return a > b;
}

void Try (int i, int sum, int pos){
	if (p[sum]){
		vector <int> res(x + 1, x + i);
		sort(res.begin(), res.end(), cmp);
		v.push_back(res);
	}
	for (int j = pos; j <= n; ++j){
		x[i] = a[j];
		Try(i + 1, sum + a[j], j + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	init();
	while (t--){
		cin >> n;
		v.clear();
		for (int i = 1; i <= n; ++i) cin >> a[i];
		Try(1, 0, 1);
		sort(v.begin(), v.end());
		for (auto it : v){
			for (int x : it) cout << x << ' ';
			cout << '\n';
		}
	}
	return 0;
}