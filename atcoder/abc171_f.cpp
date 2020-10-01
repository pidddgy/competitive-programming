// https://atcoder.jp/contests/abc171/tasks/abc171_f    

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

using ll = long long;

ll fac[2000500];

const ll MOD = 1000000007LL;

ll modmul(ll a, ll b) {
    return (a*b) % MOD;
}

ll modpow(ll a, ll exp) {
    if(exp == 0) return 1LL;

    ll t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

ll modinv(ll n) {
    return modpow(n, MOD-2);
}

ll choose(ll n, ll k) {
    return modmul(fac[n], modinv(modmul(fac[k], fac[n-k])));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for(ll i = 1; i <= 2000000; i++) {
        fac[i] = modmul(fac[i-1], i);
    }

    ll K;
    string s;

    cin >> K >> s;

    ll N = s.size();

    ll ans = 0;
    // i = not same
    for(ll i = 0; i <= K; i++) {
        ll val = modmul(modpow(25, i), choose(N+K, i));
        ans += val;

        ans %= MOD;
    }

    cout << ans << endl;
}

