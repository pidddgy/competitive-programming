// https://cses.fi/problemset/task/1070

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

    int n;
    cin >> n;

    if(n > 1 and n <= 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        vector<int> odd;
        vector<int> even;

        for(int i = 1; i <= n; i++) {
            if(i&1) {
                odd.emplace_back(i);
            } else {
                even.emplace_back(i);
            }
        }

        for(int x: even) {
            cout << x << " ";
        }

        for(int x: odd) {
            cout << x << " ";
        }
        cout << endl;
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
