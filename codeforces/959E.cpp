// https://codeforces.com/contest/959/problem/E

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

    int ans = 0;
    int cur = 1;
    for(int i = 1; i <= 50; i++) {
        int next = cur*2;

        int x = (n-1)-(cur-1);
        if(x < 0) break;
        watch(x)

        int t = (x+next-1)/next;
        cerr << cur << " appears " << t << " times" << endl;
        ans += t*cur;

        cur *= 2;
        cerr << endl;
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
