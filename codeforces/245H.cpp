// https://codeforces.com/problemset/problem/245/H

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
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int SEED = 696969697;
const int MOD = (int)1e9+7;
const int maxn = 5005;

int n;
int hsh[maxn];
int sufhsh[maxn];
int seedpow[maxn];
int inv[maxn];
bool ok[maxn][maxn];

int mod(int a) {
    return (a+MOD)%MOD;
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

int gethash(int l, int r) {
    return mod(mod(hsh[r] - hsh[l-1]) * mod(inv[l]));
}

int getsufhash(int l, int r) {
    return mod(mod(sufhsh[l] - sufhsh[r+1]) * mod(inv[n-r+1]));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    n = sz(s);
    s = "."+s;

    seedpow[0] = 1;

    for(int i = 1; i < maxn; i++) {
        seedpow[i] = mod(seedpow[i-1]*SEED);
        inv[i] = modinv(seedpow[i]);
    }

    for(int i = 1; i <= n; i++) {
        hsh[i] = mod(hsh[i-1] + mod(seedpow[i] * s[i]));
    }

    for(int i = n; i >= 1; i--) {
        sufhsh[i] = mod(sufhsh[i+1] + mod(seedpow[n-i+1] * s[i]));
    }

    // watch(gethash(1, 3))
    // watch(gethash(2, 3))
    // watch(gethash(3, 4))
    // watch(getsufhash(2, 3))

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(gethash(i, j) == getsufhash(i, j)) {
                ok[i][j] = true;
            }
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;
    }
}

/*

do prefix sums
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
