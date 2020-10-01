// https://codeforces.com/contest/62/problem/B

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

const int maxk = 100500;

int l[26][maxk], r[26][maxk];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < maxk; j++) {
            l[i][j] = r[i][j] = -1;
        }
    }

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 0; i < 26; i++) {
        int last = -1;
        for(int j = 1; j <= 1e5; j++) {
            if(j <= k)
            if(s[j]-'a' == i) last = j;
            l[i][j] = last;
        }

        last = -1;
        for(int j = 1e5; j >= 1; j--) {
            if(j <= k)
            if(s[j]-'a' == i) last = j;
            r[i][j] = last;
        }
    }

    for(int ree = 1; ree <= n; ree++) {
        string t;
        cin >> t;

        int len = sz(t);
        t = "."+t;

        int ans = 0;
        for(int i = 1; i <= len; i++) {
            int x = t[i]-'a';
            watch(t[i])
            cerr << l[x][i] << " " << r[x][i] << endl;
            // watch(x)

            if((l[x][i] == -1) and (r[x][i] == -1)) {
                cerr << "adding " << len << endl;
                ans += len;
            } else {
                int mi = 1e18;

                if(l[x][i] != -1) {
                    mi = min(mi, abs(l[x][i]-i));
                }

                if(r[x][i] != -1) {
                    mi = min(mi, abs(r[x][i]-i));
                }

                cerr << "adding " << mi << endl;
                ans += mi;
            }
            cerr << endl;
        }

        cout << ans << endl;
    }
}

/*

L[26][N], R[26][N]

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
