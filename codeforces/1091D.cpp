// https://codeforces.com/problemset/problem/1091/D

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

int fac[(int)1e6+500];
const int MOD = 998244353;

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}
int modinv(int a) {
    return modpow(a, MOD-2);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for(int i = 1; i <= 1e6; i++) {
        fac[i] = fac[i-1] * i;
        fac[i] %= MOD;
    }

    int n;
    cin >> n;

    int ans = (n * fac[n]) % MOD;

    for(int k = 1; k <= n-1; k++) {
        ans -= fac[n] * modinv(fac[k]);
        ans = (ans+MOD)%MOD;
    }

    cout << (ans+MOD)%MOD << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
