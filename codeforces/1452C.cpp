// https://codeforces.com/contest/1452/problem/C

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

    map<char, int> cnt;
    string s;
    cin >> s;   

    int ans = 0;
    for(char x: s) {
        if(x == ')') {
            if(cnt['(']) {
                cnt['(']--;
                ans++;
            }
        }

        else if(x == ']') {
            if(cnt['[']) {
                cnt['[']--;
                ans++;
            }
        }

        cnt[x]++;
    }

    cout << ans << endl;
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
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
