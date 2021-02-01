// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

int a[20][20];

int ans = 0;

set<pii> v;

set<int> hashes;
const int seed = 131;
const int MOD = 1e9+7;

int mod(int num) {
    return (num+MOD) % MOD;
}

void f(int q) {
    int val = 0;
    int ree = seed;
    for(pii x: v) {
        val += mod(x.fi*ree);
        val = mod(val);
        ree *= seed;
        ree = mod(ree);

        val += mod(x.se*ree);
        val = mod(val);
        ree *= seed;
        ree = mod(ree);
    }

    if(hashes.count(val)) {

        cerr << "seen" << endl;
        for(pii x: v) {
            cerr << x.fi << " " << x.se << endl;
        }
        return;
    }
    else hashes.emplace(val);

    if(q == 8) {
        // cout << "e" << endl;
        // watch(sz(v))
        
        // for(int i = 1; i <= 8; i++) {
        //     for(int j = 1; j <= 8; j++) {
        //         if(find(all(v), pii(i, j)) != v.end()) {
        //             cout << "Q ";
        //         } else {
        //             cout << "X ";
        //         }
        //     }
        //     cout << endl;
        // }
        ans++;
        return;
    }

    // cerr << "currently on" << endl;
    // for(pii x: v) {
    //     cerr << x.fi << " " << x.se << endl;
    // }
    for(int i = 1; i <= 8; i++) {
        for(int j = 1; j <= 8; j++) {
            bool ok = true;
            if(a[i][j] == '*') ok = false;

            for(pii x: v) {
                if(i == x.fi or j == x.se or abs(i-x.fi) == abs(j-x.se)) ok = false;
            }

            if(ok) {
                v.emplace(pii(i, j));
                f(q+1);
                v.erase(pii(i, j));
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // place(2, 3);
    for(int i = 1; i <= 8; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= 8; j++) {
            a[i][j] = s[j-1];
        }
    }

    f(0);
    cout << ans << endl;
}

/*

diagonals are

1, 1
1, -1
-1, 1
-1, -1

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
