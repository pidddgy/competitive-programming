// https://dmoj.ca/problem/oly20practice119

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

int MOD = (int)1e9+7;


int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int mod(int num) {
    return (num+MOD)%MOD;
}

void solve() {
    vector<int> a(5);

    for(int i = 1; i <= 3; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    // arith
    if(a[3]-a[2] == a[2]-a[1]) {
        int d = mod(a[3]-a[2]);
        cout << mod(a[1]+mod(mod(k-1)*d)) << endl;
    } else {
        int r = a[3]/a[2];

        cout << mod((a[1] * modpow(r, k-1))%MOD) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
