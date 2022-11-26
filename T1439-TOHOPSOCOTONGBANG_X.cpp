#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, a[25], x[25], s;
vector <vector<int>> v;

void Try (int i, int sum, int pos){
	if (sum == s){
		vector <int> res(x + 1, x + i);
		v.push_back(res);
	}
	for (int j = pos; j <= n; ++j){
		if (sum + a[j] <= s){
			x[i] = a[j];
			Try(i + 1, sum + a[j], j);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1);
		v.clear();
		Try(1,0,1);
		if (v.size() == 0) cout << "-1";
		else{
			for (int i = 0; i < v.size(); ++i){
			cout << "[";
			for (int j = 0; j < v[i].size(); ++j){
				cout << v[i][j];
				if (j != v[i].size() - 1) cout << ' ';
				else cout << "]";
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
