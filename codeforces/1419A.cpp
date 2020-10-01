// https://codeforces.com/contest/1419/problem/0

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
    int n;
    cin >> n;

    string s;
    cin >> s;

    s = "."+s;
    // find which one it will end on

    if(n&1) {
        // if it is odd then the first person will end
        bool haveodd = false;

        for(int i = 1; i <= n; i += 2) {
            if((s[i]-'0')&1) {
                haveodd = true;
            }
        }

        if(haveodd) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    } else {
        // if even then second person will end
        bool haveodd = false;

        for(int i = 2; i <= n; i += 2) {
            if((s[i]-'0')&1) {
                haveodd = true;
            }
        }

        if(haveodd) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }

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

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
