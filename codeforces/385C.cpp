// https://codeforces.com/contest/385/problem/C

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
const int maxn = (int)1e6+50;
const int maxv = (int)1e7+500;

int psa[maxv];
int spf[maxv];

void go(int n) {
    // cerr << "on " << n << endl;
    set<int> factors;
    while(n != 1) {
        // watch(spf[n])
        factors.emplace(spf[n]);

        int cpy = spf[n];

        while(spf[n] == cpy)
            n /= spf[n];
    }

    for(int x: factors) {
        psa[x]++;
    }
    // cerr << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 1e7; i++) spf[i] = i;

    for(int i = 2; i*i <= 1e7; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= 1e7; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    // go(8388608);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        go(a);
    }

    for(int i = 1; i < maxv; i++) psa[i] += psa[i-1];

    int m;
    cin >> m;

    while(m--) {
        int l, r;
        cin >> l >> r;

        cout << psa[min((int)1e7, r)] - psa[min((int)1e7, l-1)] << endl;
    }
}

/*

get all factors of each number. Put in prefix sum array and query

use logn factorization by storing spf
if spf[i] == i, then it is a prime number, uses sieve

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
