// https://codeforces.com/contest/959/problem/E

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define cerr cout
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
    cin.tie(0);

    int n;
    cin >> n;

    map<int, vector<int>> m;
    for(int i= 1; i <= n-1; i++) {
        for(int j = 0; j <= 10; j++) {
            if((1LL << j) & i) {
                m[j+1].emplace_back(i);
                break;
            }
        }
    }

    for(auto x: m) {
        cerr << x.fi << " -> ";
        cerr << sz(x.se) << endl;
        // for(int y: x.se) {
            // cerr << y << " ";
        // }
        cerr << endl;
    }
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
