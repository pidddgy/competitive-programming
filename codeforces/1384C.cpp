// https://codeforces.com/contest/1384/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

map<char, char> dsu;

char findp(char x) {
    if(dsu[x] == x) {
        return x;
    } else {
        return dsu[x] = findp(dsu[x]);
    }
}

void merge(char a, char b) {
    char c = findp(a);
    char d = findp(b);

    dsu[c] = d;
}

void cl() {
    for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
        dsu[x] = x;
    }
}

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    s = "."+s;
    t = "."+t;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] > t[i]) {
            cout << -1 << endl;
            return;
        }

        if(findp(s[i]) != findp(t[i])) {
            merge(s[i], t[i]);
            ans++;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cl();
        solve();
    }
}

/*

*/

// Did you read the bounds correctly?
// Did you make typos?
// Array out of bounds?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
