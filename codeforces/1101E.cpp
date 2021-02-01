// https://codeforces.com/contest/1101/problem/E

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

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int r = 0, c = 0;
    for(int i = 1; i <= n; i++) {
        char type;
        cin >> type;
        if(type == '+') {
            int x, y;
            cin >> x >> y;

            if(x < y) swap(x, y);

            r = max(r, x);
            c = max(c, y);
        } else {
            int x, y;
            cin >> x >> y;
            if(x < y) swap(x, y);

            if(r <= x and c <= y) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        cerr << r << " " << c << endl;
    }
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
