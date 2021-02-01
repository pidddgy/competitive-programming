// https://codeforces.com/contest/1445/problem/D

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
const int maxn = 150500;

int fac[2*maxn];
int a[2*maxn];

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int nk(int n, int k) {
    if(n < k) return 0;
    return (fac[n] * (modinv(fac[k])*modinv(fac[n-k]) % MOD)) % MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for(int i = 1; i < 2*maxn; i++) {
        fac[i] = (fac[i-1]*i)%MOD;
    }

    int n;
    cin >> n;

    for(int i = 1; i <= 2*n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+2*n+1);

    int l = 0, r = 0;
    for(int i = 1; i <= n; i++) {
        l += a[i];
    }

    for(int i = n+1; i <= 2*n; i++) {
        r += a[i];
    }

    int x = r-l;
    watch(x)
    watch(nk(2*n, n))
    x %= MOD;

    cout << (x*nk(2*n, n))%MOD << endl;

    
}

/*

consider smallest n elements L, biggest n elements R
partitions are all the same because if an element is in L, it must be matched with an element in R

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
