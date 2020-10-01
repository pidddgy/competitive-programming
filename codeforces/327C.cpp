// https://codeforces.com/contest/327/problem/C

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

const int MOD = (int)1e9+7;

int md(int num) {
    return (num+MOD)%MOD;
}

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return md(md(t*t) * a);
    return md(t*t);
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int geosum(int a, int r, int n) {
    return md(md(a*(md((1-modpow(r, n))*modinv(1-r)))));
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int k;
    cin >> k;

    int ans = 0;
    for(int i = 0; i < sz(s); i++) {
        if(s[i] == '0' or s[i] == '5') {
            ans += geosum(modpow(2LL, i), modpow(2LL, sz(s)), k);
        }

        ans = md(md(ans));
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
