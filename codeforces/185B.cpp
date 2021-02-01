// https://codeforces.com/contest/185/problem/B

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

ld a[5];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    ld S;
    cin >> S;

    for(int i = 1; i <= 3; i++) {
        cin >> a[i];
    }

    int sum = a[1]+a[2]+a[3];
    if(sum == 0) {
        cout << 0 << " " << 0 << " " << 0 << endl;
    } else {
        for(int i = 1; i <= 3; i++) {
            cout << a[i]*(S/sum) << " ";
        }
        cout << endl;
    }

}

/*

give each turn proportional to a/b/c

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
