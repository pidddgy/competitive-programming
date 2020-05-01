// https://codeforces.com/contest/1062/problem/C

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;


int modpow(int b, int exp, int mod = MOD){if(exp == 0) return 1;int t = modpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

// a = first term, r = common ratio, n = num terms
int geosum(int a, int r, int n) {
    return (a * ((1 - modpow(r, n)) / (1 - r))) % MOD;
}

signed main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    s = "."+s;

    int psa[n+1];
    psa[0] = 0;

    for(int i = 1; i <= n; i++) {
        psa[i] = (s[i]-'0') + psa[i-1];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
 
        int o = (psa[r] - psa[l-1]) % MOD;
        int z = (((r-l)+1) - o) % MOD;

        int os = geosum(1, 2, o) % MOD;
        int zst = modpow(2, o)-1 ;
        int zs = geosum(zst, 2, z) % MOD;

        cout << (os + zs) % MOD << endl;
    }
}