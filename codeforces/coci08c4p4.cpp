#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define cerr cout
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 600;

bool a[maxn][maxn];
int psa[maxn][maxn];
int ans[maxn][maxn];
int best[maxn][maxn];
int out[maxn][maxn];
    int n;

int query(int i, int j, int ii, int jj) {
    return psa[ii][jj] - psa[i-1][jj] - psa[ii][j-1] + psa[i-1][j-1];
}

int dfs(int r, int c, int slen) {
    if(slen == 1) {
        ans[r][c] = a[r][c];
        return 0;
    }

    int nl = slen/2;
    vector<pii> v = {pii(r, c), pii(r+nl, c), pii(r, c+nl), pii(r+nl, c+nl)};

    sort(all(v));

    int mi = INT_MAX;
    do {
    cerr << "on " << r << " " << c << " " << slen << " -> ";
        for(pii x: v) {
            cerr << x.fi << "," << x.se << " ";
        }
        cerr << endl;
        int loc = 0;
        // 0 = white
        loc += query(v[0].fi, v[0].se, v[0].fi+nl-1, v[0].se+nl-1);
        watch(query(v[0].fi, v[0].se, v[0].fi+nl-1, v[0].se+nl-1))

        // 1 = black
        loc += nl*nl - query(v[1].fi, v[1].se, v[1].fi+nl-1, v[1].se+nl-1);
        watch(nl*nl - query(v[1].fi, v[1].se, v[1].fi+nl-1, v[1].se+nl-1))

        cerr << "d after first two are " << loc << endl;

        watch(nl)
        for(int i = 0; i < nl; i++) {
            for(int j = 0; j < nl; j++) {
                cerr << "setting " << v[0].fi+i << " " << v[0].se+j << " to 0" << endl;
                ans[v[0].fi+i][v[0].se+j] = 0;
                ans[v[1].fi+i][v[1].se+j] = 1;
            }
        }

        loc += dfs(v[2].fi, v[2].se, nl);
        loc += dfs(v[3].fi, v[3].se, nl);

        if(loc < mi) {
            mi = loc;
            for(int i = 0; i < slen; i++) {
                for(int j = 0; j < slen; j++) {
                    best[r+i][c+j] = ans[r+i][c+j];
                    if(r == 1 and c == 1 and slen == n) {
                        out[r+i][c+j] = best[r+i][c+j];
                    }
                }
            }
        }
        cerr << "loc for " << r << " " << c << " " << slen << " -> ";
        for(pii x: v) {
            cerr << x.fi << "," << x.se << " ";
        }
        cerr << "is " << loc << endl;
        cerr << endl;

        for(int i = 0; i < slen; i++) {
            for(int j = 0; j < slen; j++) {
                cerr << ans[r+i][c+j];
            }
            cerr << endl;
        }

        
    } while(next_permutation(all(v)));

    return mi;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= n; j++) {
            a[i][j] = s[j-1]-'0';
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + a[i][j];
        }
    }    

    cout << dfs(1, 1, n) << endl;

    // watch(query(3, 3, 4, 4))
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << out[i][j];
        }
        cout << endl;
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