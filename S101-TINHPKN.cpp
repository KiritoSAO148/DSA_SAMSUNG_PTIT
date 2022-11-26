#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
using ll = long long;

ll nPk(int n, int k){
	if (n<k) return 0;
	ll res=1;
	for (int i=0; i<k; i++){
		res=res*(n-i);
		res%=MOD;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		cout << nPk(n,k) << endl;
	}
	return 0;
}
