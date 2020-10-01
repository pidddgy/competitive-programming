// https://codeforces.com/contest/1392/problem/B

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
    int n, k;
    cin >> n >> k;

    vector<int> a;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        a.push_back(x);
    }

    if(k&1) {
        int ma = *max_element(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            a[i] = ma-a[i];
        }
    } else {
        int ma = *max_element(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            a[i] = ma-a[i];
        }

        ma = *max_element(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            a[i] = ma-a[i];
        }
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*
UHH SOME MATH THING IDK

for some reason it just flips between two
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
