// https://atcoder.jp/contests/abc165/tasks/abc165_a

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
    cin.tie(0);

    int a, b, k;
    cin >> k >> a >> b;

    for(int i = 0; i <= 42069; i++) {
        int x = i*k;

        if(a <= x and x <= b) {
            cout << "OK" << endl;
            return 0;
        }
    }

    cout << "NG" << endl;
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
