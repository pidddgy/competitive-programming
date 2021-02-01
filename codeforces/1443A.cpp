// https://codeforces.com/contest/1443/problem/0

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

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

void solve(int n) {
    vector<int> ans;

    for(int i = 4*n; i >= 1; i -= 2) {
        ans.emplace_back(i);
        cerr << "appending " << i << endl;
        
        if(sz(ans) == n) {
            break;
        }
    }

    for(int i = 0; i < sz(ans); i++) {
        for(int j = 0; j < sz(ans); j++) {
            if(i == j) continue;

            assert(gcd(ans[i], ans[j]) != 1);
            assert(ans[i]%ans[j]);
            assert(ans[j]%ans[i]);
        }
    }
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    // for(int i = 1; i <= 100; i++) {
    //     cerr << "trying " << i << endl;
    //     solve(i);
    // }
    while(t--) {
        int x;
        cin >> x;

        solve(x);
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
