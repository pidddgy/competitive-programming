// https://codeforces.com/problemset/problem/201/A

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

int grid[200][200];

void clear() {
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            grid[i][j] = 0;
        }
    }
}

struct Compare {
    bool operator()(set<pii> &l, set<pii> &r) {
        return sz(l) > sz(r);
    }
};

vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok(int i, int j) {
    if(grid[i][j]) return false;
    for(pii d: dir) {
        if(grid[i+d.fi][j+d.se]) return false;
    }  

    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    for(int n = 1; n <= 100; n++) {
        clear();

        vector<set<pii>> groups;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                set<pii> S = {
                    pii(i, j),
                    pii(n-i+1, j),
                    pii(i, n-j+1),
                    pii(n-i+1, n-j+1)
                };

                groups.emplace_back(S);
            }
        }

        stable_sort(all(groups));

        cerr << "trying " << n << endl;
        int have = 0;
        for(set<pii> S: groups) {
            bool good = true;
            // for(pii p: S) {
            //     cerr << p.fi << " " << p.se << endl;
            // }

            for(pii p: S) {
                if(!ok(p.fi, p.se)) {
                    good = false;
                }
                for(pii d: dir) {
                    if(S.count(pii(p.fi+d.fi, p.se+d.se))) {
                        good = false;
                    }
                }
            }

            if((good) and (have+sz(S) <= x)) {
                for(pii p: S) {
                    grid[p.fi][p.se] = 1;
                }
                have += sz(S);
            }
            // cerr << endl;
        }

        // watch(have)
                    for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    cerr << grid[i][j] << " ";
                }
                cerr << endl;
            }
        if(have == x) {
            cout << n << endl;
            return 0;
        }
    }

    
}

/*
4 000 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
