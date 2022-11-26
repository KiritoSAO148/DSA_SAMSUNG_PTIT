#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TC() int t; cin >> t; while (t--)
#define el cout << "\n"
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn 

const int MOD = (int) 1e9+7;

void FileIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

ll count (ll n, ll k){
    ll m = max((ll)sqrt(n), k);
    vector <bool> prime(m + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= sqrt(sz(prime)); ++i){
        if (prime[i]){
            for (ll j = i * i; j <= sz(prime); j += i)
                prime[j] = false;
        }
    }
    vl mau(k + 1);
    for (ll i = 1; i <= k; ++i) mau[i] = i;
    vl tu(k);
    ll offset = n - k + 1;
    for (ll i = 0; i < k; ++i) tu[i] = offset + i;
    ll ans = 1;
    for (ll p = 2; p < sz(prime); ++p){
        if (prime[p]){
            ll power = 0;
            for (ll i = p; i <= k; i += p){
                while (mau[i] % p == 0){
                    --power;
                    mau[i] /= p;
                }
            }
            for (ll i = ((n - k + 1) + p - 1) / p * p; i <= n; i += p){
                while (tu[i - offset] % p == 0){
                    ++power;
                    tu[i - offset] /= p;
                }
            }
            ans *= (power + 1);
        }
    }
    for (ll i = n - k + 1; i <= n; ++i){
        if (tu[i - offset] != 1){
            ans *= 2;
        }
    }
    return ans;
}

int main(){
    FileIO();
    FastIO;
    ll a, b;
    while (cin >> a >> b){
    	cout << count(a,b); el;
    }
    return 0;
}