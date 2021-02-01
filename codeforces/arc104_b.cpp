// https://atcoder.jp/contests/arc104/tasks/arc104_b

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

    string s;
    cin >> s;

    s = "."+s;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        map<char, int> cnt;
        for(int j = i; j <= n; j++) {
            cnt[s[j]]++;

            if(cnt['A'] == cnt['T'] and cnt['C'] == cnt['G']) {
                ans++;
            }
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
