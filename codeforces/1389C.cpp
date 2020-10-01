// https://codeforces.com/contest/1389/problem/C

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
#define all(x) (x).begin(), (x).end()

string s;

void solve() {
    cin >> s;
    int n = s.size();
    s = "."+s;    

    int ans = INT_MAX;
    for(char x: string("0123456789")) {
        for(char y: string("0123456789")) {
            int rem = 0, cur = 0;
            vector<char> nums = {x, y};

            for(int i = 1; i <= n; i++) {
                if(s[i] == nums[cur]) {
                    cur ^= 1;
                } else {
                    rem++;
                }
            }

            if(cur == 1 and x != y) {
                rem++;
            }

            ans = min(ans, rem);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
