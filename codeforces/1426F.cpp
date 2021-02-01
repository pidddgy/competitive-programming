// https://codeforces.com/problemset/problem/1426/F

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

const int maxn = 200500;
const int MOD = (int)1e9+7;

int mod(int num) {
    return (num+MOD)%MOD;
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

map<char, int> pre[maxn], suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        pre[i][s[i]]++;
        for(char x: string("?abc")) {
            pre[i][x] += pre[i-1][x];
        }
    }

    for(int i = n; i >= 1; i--) {
        suf[i][s[i]]++;
        for(char x: string("?abc")) {
            suf[i][x] += suf[i+1][x];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '?' or s[i] == 'b') {
            int ql = pre[i-1]['?'];
            int qr = suf[i+1]['?'];

            // pick one question mark, the others can be whatever
            int a = mod(mod(mod(mod(ql * modpow(3, ql-1))) * suf[i+1]['c']) * modpow(3, qr));
            int b = mod(mod(mod(ql * modpow(3, ql-1)) * qr) * modpow(3, qr-1));
            int c = mod(mod(mod(modpow(3, ql) * pre[i-1]['a']) * qr) * modpow(3, qr-1));
            int d = mod(mod(mod(pre[i-1]['a'] * suf[i+1]['c']) * modpow(3, ql)) * modpow(3, qr));

            ans += mod(mod(a+b)+mod(c+d));
            ans = mod(ans);
        } 
    }

    cout << mod(mod(mod(ans))) << endl;
}

/*

consider each point as ? or b

case 1: use question mark on left
case 2: use question mark on both
case 3: use question mark on right
case 4: no question mark

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
