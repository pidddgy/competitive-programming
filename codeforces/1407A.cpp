// https://codeforces.com/contest/1407/problem/0

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

int a[100500];
void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    int i = 1;
    while(i <= n) {
        if((a[i] == a[i+1])) {
            i += 2;
            continue;
        }
        
        if((i+2 <= n) and (a[i] == a[i+2])) {
            ans.emplace_back(a[i+1]);
            i += 3;
        } else {
            ans.emplace_back(a[i]);
            i++;
        }
    }

    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
    // cerr << "~~~~" << endl;

    for(int i = 1; i <= n; i++) a[i] = 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

think about trying to "fix" positions
it never makes sense to delete more than 2 elements to fix a certain position

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
