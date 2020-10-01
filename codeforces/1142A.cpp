// https://codeforces.com/contest/1142/problem/A

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

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    int mi = LLONG_MAX, ma = LLONG_MIN;
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 1; j++) {
            int A, B;
            if(i) A = a;
            else A = k-a;

            if(j) B = b;
            else B = k-b;

            int x = (A-B+k)%k;

            for(int l = 0; l < n; l++) {
                int v = __gcd(n*k, x+ k*l);
                mi = min(mi, (n*k) / v);
                ma = max(ma, (n*k) / v);
            }
        }
    }

    cout << mi << " " << ma << endl;
}

/*

use 0 index and mod

pick starting place, min/max

each starting point gives a residue mod n*k

x = distance per hop

ax = n*k

brute force if first/second is on left side or right side

if we know length it is nk / gcd(nk, l) moves




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
