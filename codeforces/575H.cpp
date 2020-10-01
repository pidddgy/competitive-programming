// https://codeforces.com/contest/575/problem/H

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

const int MOD = (int)1e9+7;
int fac[2000500];

int modmul(int a, int b) {
    return (a*b) % MOD;
}

int modpow(int a, int exp) {
    if(exp == 0) return 1LL;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int n) {
    return modpow(n, MOD-2);
}

int choose(int n, int k) {
    return modmul(fac[n], modinv(modmul(fac[k], fac[n-k])));
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for(int i = 1; i <= 2000050; i++) {
        fac[i] = modmul(fac[i-1], i);
    }

    int n;
    cin >> n;

    cout << ((choose(2*n+2, n+1)-1)+MOD)%MOD << endl;
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
