// https://codeforces.com/contest/835/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int maxn = 5500;
const int seed = 197;

string s;
int n;

int hsh[maxn], sufhsh[maxn], seedpows[maxn];
bool dp[2][maxn][maxn];
int ans[maxn];

int gethsh(int l, int r) {
    return hsh[r] - hsh[l-1];
}

int getsufhsh(int l, int r) {
    return sufhsh[l] - sufhsh[r+1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = s.size();
    s = "."+s;

    seedpows[0] = 1;
    for(int i = 1; i < maxn; i++) {
        seedpows[i] = seedpows[i-1]*seed;
    }

    for(int i = 1; i <= n; i++) {
        hsh[i] = hsh[i-1] + s[i]*seedpows[i-1];
    }

    for(int i = n; i >= 1; i--) {
        sufhsh[i] = sufhsh[i+1] + s[i]*seedpows[n-i];
    }

    for(int i = 1; i <= n; i++) {
        cerr << hsh[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        cerr << sufhsh[i] << " ";
    }
    cerr << endl;

    int ans = 0;
    for(int j = 1; j <= n; j++) {
        for(int k = j; k <= n; k++) {
            int p = gethsh(j, k);
            int s = getsufhsh(j, k);

            // How much did we "chop off"
            int pc = j-1;
            int sc = n-k;

            if(pc > sc) {
                s *= seedpows[pc-sc];
            } else if(sc > pc) {
                p *= seedpows[sc-pc];
            }

            // cerr << "for " << j << " " << k << " pref chopped off " << pc << " and suf chopped " << sc << endl;
            // cerr << s << " " << p << endl;
            // cerr << endl;

            if(s == p) {
                dp[1][j][k] = true;
                ans++;
            }
        }
    }

    cout << ans << " ";

    for(int i = 2; i <= min(13, n); i++) {
        int cur = i%2;
        int prev = cur^1;

        ans = 0;

        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                dp[cur][j][k] = false;
            }
        }

        for(int j = 1; j <= n; j++) {
            for(int k = j; k <= n; k++) {
                int p = gethsh(j, k);
                int s = getsufhsh(j, k);

                // How much did we "chop off"
                int pc = j-1;
                int sc = n-k;

                if(pc > sc) {
                    s *= seedpows[pc-sc];
                } else if(sc > pc) {
                    p *= seedpows[sc-pc];
                }

                // cerr << "for " << j << " " << k << " pref chopped off " << pc << " and suf chopped " << sc << endl;
                // cerr << s << " " << p << endl;
                // cerr << endl;

                if(p == s) {
                    int len = k-j+1;
                    int shift = len/2;

                    if(dp[prev][j][j+shift-1] and dp[prev][k-shift+1][k]) {
                        dp[cur][j][k] = true;
                        ans++;
                    }
                    // int l = gethsh(j, j+shift-1);
                    // int r = gethsh(k-shift+1, k);
                }
            }
        }
        cout << ans << " ";
        ans = 0;
    }

    for(int i = 1; i <= n-13; i++) {
        cout << 0 << " ";
    }
    cout << endl;
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