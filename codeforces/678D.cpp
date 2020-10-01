// https://codeforces.com/contest/678/problem/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1000000007;

ll modpow(ll a, ll exp){
    if(exp == 0) return 1;
    ll t = modpow(a, exp/2);
    
    // If odd
    if(exp % 2 == 1) {
        return ((t*t % MOD) * (a % MOD)) % MOD;
    } else {
        return t*t%MOD;
    }
}

ll geosum(ll a, ll r, ll n) {
    if(r==1) return n;
    if(n==1) return 1LL;
    return (a * ((modpow(r, n)-1) * modpow(r-1, MOD-2) % MOD)) % MOD;
}

signed main() {
    // Input A, B, n, x
    ll A, B, n, x;
    cin >> A >> B >> n >> x;

    ll ans = ((x*modpow(A, n))%MOD + ((B*(geosum(1LL, A, n)%MOD))%MOD)%MOD) % MOD;

    // Print ans
    cout << ans << endl;
}
