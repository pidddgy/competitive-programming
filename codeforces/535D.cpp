// https://codeforces.com/contest/535/problem/D

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
const int maxn = (int)1e6+50;
const int seed = 197;

string s;

int mod(int a) {
    return (a+MOD)%MOD;
}

int modpow(int a, int exp) {
    if(exp == 0) return 1;
    if(exp == 1) return a;

    int t = modpow(a, exp/2);

    if(exp&1) {
        return mod(mod(t*t)*a);
    } else {
        return mod(t*t);
    }
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int spow[maxn];
int invspow[maxn];
int hsh[maxn];
int gethash(int l, int r) {
    return mod(mod(hsh[r]-hsh[l-1])*invspow[l]);
}

int n, m;
int y[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n+30; i++) {
        s.push_back('?');
    }

    spow[0] = 1;
    for(int i = 1; i <= n; i++) {
        spow[i] = mod(spow[i-1]*seed);
    }

    for(int i = 0; i <= n; i++) {
        invspow[i] = modinv(spow[i]);
    }

    string p;
    cin >> p;

    for(int i = 1; i <= m; i++) {
        cin >> y[i];
    }

    // int ree = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < sz(p); j++) {
            if(i < m) {
                if(y[i]+j == y[i+1]) break;
            }

            s[y[i]+j] = p[j];
            // ree++;

            // assert(ree <= n);
        }
    }

    for(int i = 1; i <= n; i++) {
        hsh[i] = mod(hsh[i-1]+mod(s[i]*spow[i]));
    }

    int hashval = 0;
    for(int i = 0; i < sz(p); i++) {
        hashval += mod(p[i]*spow[i]);
        hashval = mod(hashval);
    }

    watch(s)

    bool ok = true;
    for(int i = 1; i <= m; i++) {
        if(gethash(y[i], y[i]+sz(p)-1) != hashval) {
            cerr << "failed on " << i << endl;
            ok = false;
        }
    }

    if(!ok) {
        cout << 0 << endl;
        return 0;
    }

    int undef = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '?') undef++;
    }


    cout << modpow(26, undef) << endl;
}

/*

answer is pow(n-fixed chars, 26)

use hashing to check

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?