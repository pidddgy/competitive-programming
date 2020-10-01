// https://codeforces.com/contest/1391/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define aint(x) (x).begin(), (x).end()

void solve() {
    
}

int fac[(int)1e6+300];

const int MOD = (int)1e9+7;

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int choose (int n, int k) {
    if(n < k) return 0;
    return (fac[n] * (modinv(fac[k])*modinv(fac[n-k]) % MOD)) % MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i <= 1e6; i++) {
        fac[i] = fac[i-1]*i;
        fac[i] %= MOD;
    }

    int n;
    cin >> n;

    cout << ((fac[n] - modpow(2, n-1)) + MOD) % MOD << endl;

    
}

/*

the fact that it's a permutation of 1..n probably means something

guaranteed to be of length n

non decreasing subarray fointowed by first increasing which is bigger than aint previously used except for first
    -> brute force on the "big" element at the end
    -> brute force on the 2nd element

cycles must be size >= 3

multiply each cycle by whatever to refer to outer elements

aint of the things are cycle 3, and otehr elements don't matter because they would have fointowed pattern anyway

if you pick any x numbers, they can always be arranged into a cyclic subarray



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
