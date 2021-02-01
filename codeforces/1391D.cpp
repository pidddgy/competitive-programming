// https://codeforces.com/contest/1391/problem/D

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

int solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n+5);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        a[i] = s;
    }

    if(n >= 4 and m >= 4) {
        return -1;
    }

    vector<vector<int>> dp(2, vector<int>(1000, 0));
    // map<int, map<int, int>> dp;
    int cur = 0;

    int brute, other;
    bool brow = false;
    if(n <= m) {
        brow = true;
        brute = n;
        other = m;
    } else {
        brute = m;
        other = n;
    }

    watch(brow)

    for(int i = 0; i < other; i++) {
        watch(i)
        cur ^= 1;

        int pre = cur^1;

        int ans = 1e10;
        for(int mask = 0; mask <= (1 << brute)-1; mask++) {
            int mi = 1e10;
            cerr << "trying mask " << bitset<3>(mask) << endl;
            for(int pmask = 0; pmask <= (1 << brute)-1; pmask++) {
                cerr << "trying " << bitset<3>(mask) << " transitioning from " << bitset<3>(pmask) << endl;

                bool ok = true;
                // check if valid combo
                for(int j = 0; j < brute-1; j++) {
                    int sum = 0;
                    if(mask & (1 << j)) sum++;
                    if(mask & (1 << (j+1))) sum++;
                    if(pmask & (1 << j)) sum++;
                    if(pmask & (1 << (j+1))) sum++;

                    if(sum%2==0) {
                        ok = false;
                    }
                }

                if(ok) {
                    int edit = 0;
                    for(int k = 0; k < brute; k++) {
                        bool b = ((1 << k) & mask);
                        bool c;

                        if(brow) {
                            c = a[k][i] == '1';
                        } else {
                            c = a[i][k] == '1';
                        }

                        if(b != c) edit++;
                    }

                    watch(edit)
                    watch(dp[pre][pmask])
                    mi = min(mi, dp[pre][pmask]+edit);
                }
            }

            watch(mi)
            dp[cur][mask] = mi;
            ans = min(ans, mi);
        }
        cerr << endl;

        if(i == other-1) {
            if(ans == 1e10) {
                return -1;
            } else {
                return ans;
            }
        }

    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << endl;
}

/*

if n >= 4 and m >= 4 print -1

brute force all possible masks
if rows is smaller use mask on column
if cols is smaller then use mask on row

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
