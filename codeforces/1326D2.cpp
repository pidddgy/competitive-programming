// https://codeforces.com/contest/1326/problem/D2

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

const int SEED = 696969697;
const int MOD = (int)1e9+7;
const int MAXN = (int)1e6+5;

int n;
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

int hsh[MAXN], sufhsh[MAXN], spow[MAXN], inv[MAXN];


int gethash(int l, int r) {
    return mod(mod(hsh[r] - hsh[l-1]) * mod(inv[l]));
}

int getsufhash(int l, int r) {
    return mod(mod(sufhsh[l] - sufhsh[r+1]) * mod(inv[n-r+1]));
}

bool pal(int l, int r) {
    return gethash(l, r) == getsufhash(l, r);
}

void solve() {
    string s;
    cin >> s;

    n = sz(s);

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        hsh[i] = mod(hsh[i-1] + mod(spow[i] * s[i]));
    }

    for(int i = n; i >= 1; i--) {
        sufhsh[i] = mod(sufhsh[i+1] + mod(spow[n-i+1] * s[i]));
    }

    int ma = 0;
    for(int i = 1; i <= n/2; i++) {
        if(gethash(1, i) == getsufhash(n-i+1, n)) ma = i;
    }

    watch(ma)
    int ma2 = 0, ma3 = 0;
    for(int i = ma+1; i <= n-ma; i++) {
        if(pal(ma+1, i)) ma2 = max(ma2, i-ma);
        if(pal(i, n-ma)) ma3 = max(ma3, n-ma-i+1);
    }

    watch(ma2)
    watch(ma3)

    if(ma2 >= ma3) {
        cerr << "Hiii" << endl;
        for(int i = 1; i <= ma+ma2; i++) {
            watch(i)
            cout << s[i];
        }
        for(int i = n-ma+1; i <= n; i++) {
            cout << s[n-i+1];
        }
        cout << endl;
    } else {
        for(int i = 1; i <= ma; i++) {
            cout << s[i];
        }

        for(int i = n-(ma+ma3)+1; i <= n; i++) {
            cout << s[i];
        }
        cout << endl;
    }

    // clear everything    
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    spow[0] = 1;
    for(int i = 1; i <= 1e6; i++) {
        spow[i] = mod(spow[i-1]*SEED);
    }

    for(int i = 1; i <= 1e6; i++) {
        inv[i] = modinv(spow[i]);
    }

    int t;
    cin >> t;

    while(t--) solve();
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
