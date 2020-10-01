// https://codeforces.com/contest/533/problem/C

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

    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;

    // can reach faster than second person can "get into box" of first
    // proof by showing that this condition can always be maintained, and at some point polycarp will hit 0 first because he goes first
    if(xp + yp <= max(xv, yv)) {
        cout << "Polycarp" << endl;
    } else if(xp <= xv and yp <= yv) { // first person can block diagonal movement when the second person comes
        cout << "Polycarp" << endl;
    } else {
        cout << "Vasiliy" << endl;
    }
}

/*

second person will take max(x, y) moves

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
