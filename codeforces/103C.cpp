#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x);
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    while(q--) {
        int x;
        cin >> x;

        if(n%2 == 1) {
            if(x == n and k) {
                cout << "X";
            } else {
                int dis;
                if(x%2 != n%2) {
                    dis = (((n-1)-(x))/2)+1;
                } else {
                    dis = ((n/2)+1) + ((n-2)-x)/2;
                }

                if(dis < k) {
                    cout << "X";
                } else {
                    cout << ".";
                }
            }
        } else {
            int dis;
            if(x%2 == n%2) {
                dis = (n-x)/2;
            } else {
                dis = (n/2) + ((n-1)-x)/2;
            }

            if(dis < k) {
                cout << "X";
            } else {
                cout << ".";
            }
        }
    }

    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
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
