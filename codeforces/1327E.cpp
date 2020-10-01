// https://codeforces.com/problemset/problem/1327/E

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
int pows[200500];
int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    pows[0] = 1;
    for(int i = 1; i <= 2e5; i++) {
        pows[i] = pows[i-1]*10;
        pows[i] %= MOD;
    }

    int n;
    cin >> n;

    for(int len = 1; len <= n-1; len++) {
        int a = (2LL * 10LL * 9LL * pows[n-len-1]) % MOD;
        int b = ((n-len-1) * 10LL * 9LL * 9LL * pows[max(0LL, n-len-2)]) % MOD;

        cout << (a+b) % MOD << " ";
    }

    cout << 10 << endl;
}

/*

each digit contributes the same sum to all block lengths

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
