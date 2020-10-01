// https://codeforces.com/contest/1312/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int MOD = 998244353;

const int maxn = (int)2e5+50;

int fac[maxn];
int modmul(int a, int b) {
    return (a*b) % MOD;
}

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int choose(int n, int k) {
    return modmul(fac[n], modinv(modmul(fac[k], fac[n-k])));
}

int md(int num) {
    return (num+MOD)%MOD;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for(int i = 1; i <= 2e5; i++) {
        fac[i] = fac[i-1]*i;
        fac[i] %= MOD;
    }

    int ans = 0;

    int n, m;
    cin >> n >> m;

    watch(choose(m, n-1))
    if(n > 2) {
        ans = modmul(choose(m, n-1), modmul(n-2, modpow(2, n-3)));
    }

    cout << ans << endl;
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
