#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//#define maxn 500
//
//int p[maxn + 1];
//
//void init(){
//	for (int i = 1; i <= maxn; ++i) p[i] = 1;
//	p[0] = p[1] = 0;
//	for (int i = 2; i <= sqrt(maxn); ++i){
//		if (p[i]){
//			for (int j = i * i; j <= maxn; j += i) p[j] = 0;
//		}
//	}
//}

//int prime (int n){
//	if (n < 2) return 0;
//	for (int i = 2; i <= sqrt(n); ++i){
//		if (n % i == 0) return 0;
//	}
//	return 1;
//}

int n, a[20], x[20];
vector <vector<int>> v;

void Try (int i, int sum, int pos){
	for (int j = pos; j >= 1; --j){
		x[i] = j;
		if (sum == n){
			vector <int> res(x + 1, x + i);
			v.push_back(res);
			return;
		}
		else if (sum + j <= n) Try(i + 1, sum + j, j);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while (t--){
		cin >> n;
		v.clear();
		Try(1, 0, n);
		for (int i = 0; i < v.size(); ++i){
			cout << "(";
			for (int j = 0; j < v[i].size(); ++j){
				cout << v[i][j];
				if (j != v[i].size() - 1) cout << ' ';
				else cout << ") ";
			}
		}
		cout << '\n';
	}
	return 0;
}
