#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define f0(i,n) for (int i = 0; i < n; ++i)
typedef vector<int> vi;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	FastIO;
	int n, m; cin >> n >> m;
	vi a(n);
	map <int, int> mp;
	f0 (i,n) cin >> a[i], mp[a[i]]++;
	int max1 = 0, max2 = 0, check = 0, ans = 0;
	for (auto it : mp) max1 = max(max1, it.se);
	for (auto it : mp){
		if (it.se > max2 && it.se < max1){
			max2 = it.se;
			ans = it.fi;
			check = 1;
		}
	}
	if (!check) return cout << "NONE", 0;
	cout << ans;
	return 0;
}