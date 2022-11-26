#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k; cin >> n >> k;
	vector <int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	int cnt = 1;
	for (int i = 0; i < n - 1; ++i){
		if (v[i + 1] - v[i] > k) ++cnt;
	}
	cout << cnt;
	return 0;
}