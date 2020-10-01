// https://codeforces.com/problemset/problem/126/B

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

const int SEED = 696969697;
const int MOD = (int)1e9+7;

const int maxn = (int)1e6+5;

int hashes[maxn];
int seedpows[maxn];
int inv[maxn];
string s;

int mod(int n) {
    return (n+MOD)%MOD;
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
    return mod(mod(hashes[r] - hashes[l-1]) * inv[l]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    seedpows[0] = 1;
    for(int i = 1; i <= 1e6; i++) {
        seedpows[i] = mod(seedpows[i-1]*SEED);
    }

    for(int i = 1; i <= 1e6; i++) {
        inv[i] = modinv(seedpows[i]);
    }

    cin >> s;
    int n = sz(s);
    s = "."+s;

    for(int i = 1; i <= n; i++) {
        hashes[i] = mod(hashes[i-1] + mod(seedpows[i]*s[i]));
    }

    vector<int> valid;
    for(int len = 1; len <= n; len++) {
        int pre = gethash(1, len);
        int suf = gethash(n-len+1, n);

        if(pre == suf) {
            valid.emplace_back(len);
        }
    }

    int ans = -1;
    for(int i = 2; i <= n-1; i++) {
        int l = ans+1;
        int r = sz(valid)-1;
        int lgood = -1;

        while(l <= r) {
            int m = (l+r)/2;
            int len = valid[m];

            if(i+len-1 >= n) {
                r = m-1;
                continue;
            }

            if(gethash(i, i+len-1) == gethash(1, len)) {
                ans = max(m, ans);
                l = m+1;
            } else {
                r = m-1;
            }
        }
    }

    if(ans == -1) {
        cout << "Just a legend" << endl;
    } else {
        for(int i = 1; i <= valid[ans]; i++) {
            cout << s[i];
        }
        cout << endl;
    }
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
