// https://codeforces.com/contest/487/problem/A

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

    int hpy, atky, defy;
    cin >> hpy >> atky >> defy;

    int hpm, atkm, defm;
    cin >> hpm >> atkm >> defm;

    int h, a, d;
    cin >> h >> a >> d;

    int ans = LLONG_MAX;
    // will nevern eed more than 300 attack (loose bound)
    // i = attack, j = def
    for(int i = max(defm+1, atky); i <= 300; i++) {
        for(int j = defy; j <= 150; j++) {
            int t = i-defm;
            int moves = (hpm+t-1)/t;

            int t2 = max(0LL, atkm-j);

            // remaining hp
            int hp = hpy-(moves*t2);

            int cost = 0;
            if(hp <= 0) {
                cost += h*(1-hp);
            }
            cost += (i-atky)*a;
            cost += (j-defy)*d;

            ans = min(ans, cost);
        }
    }

    cout << ans << endl;
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
