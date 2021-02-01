// https://codeforces.com/contest/822/problem/D

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

const int maxn = (int)5e6;
const int MOD = (int)1e9+7;

int t, l, r;
int dp[maxn+50];
int spf[maxn+50];
int inv[maxn+50];

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int mod(int num) {
    return (num+MOD)%MOD;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    inv[2] = modinv(2);
    for(int i = 1; i <= maxn; i++) {
        spf[i] = i;
    }

    for(int i = 2; i*i <= maxn; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= maxn; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    dp[1] = 0;
    for(int i = 2; i <= maxn; i++) {
        int j = spf[i];
        int x = i/j;

        int trngj = mod(mod(j * (j-1))*inv[2]);
        dp[i] = mod(x* (trngj)) + dp[x];
    }

    cin >> t >> l >> r;

    int ans = 0;
    int e = 1;
    for(int i = l; i <= r; i++) {
        // ans += mod(modpow(t, i-l)*dp[i])%MOD;

        ans += mod(e*dp[i])%MOD;
        ans = (ans+MOD)%MOD;

        e *= t;
        e = mod(e);
    }
    
    cout << ans << endl;
}

/*

guess: divide into (smallest prime factor) groups



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
