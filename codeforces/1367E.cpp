// https://codeforces.com/contest/1367/problem/E

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

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, int> cnt;
    for(char x: s) cnt[x]++;

    for(int i = n; i >= 1; i--) {
        int rep = gcd(i, k);
        int per = i/rep;

        int beads = 0;
        for(auto x: cnt) {
            beads += x.se-(x.se%per);
        }

        if(beads >= i) {
            cout << i << endl;
            return;
        }
    }

    assert(false);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

only 26 types of beads


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
