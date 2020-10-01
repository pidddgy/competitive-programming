// https://codeforces.com/contest/1118/problem/C

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

vector<int> a[10];
int ans[50][50];

void no() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> cnt;

    for(int i = 0; i < n*n; i++) {
        int x;
        cin >> x;

        cnt[x]++;
    }

    for(pii x: cnt) {
        for(int i = 4; i >= 1; i /= 2) {
            while(cnt[x.fi] >= i) {
                a[i].emplace_back(x.fi);
                cnt[x.fi] -= i;
            }
        }
    }

    set<set<pii>> S;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            set<pii> T;

            T.emplace(i, j);
            T.emplace(n-1-i, j);
            T.emplace(i, n-1-j);
            T.emplace(n-1-i, n-1-j);

            S.emplace(T);
        }
    }

    for(auto x: S) {
        if(sz(x) == 4) {
            if(a[4].empty()) no();

            for(pii y: x) {
                ans[y.fi][y.se] = a[4].back();
            }
            a[4].pop_back();
        } else if(sz(x) == 2) {
            if(sz(a[2])) {
                for(pii y: x) {
                    ans[y.fi][y.se] = a[2].back();
                }
                a[2].pop_back();
            } else if(sz(a[4])) {
                for(pii y: x) {
                    ans[y.fi][y.se] = a[4].back();
                }
                a[2].emplace_back(a[4].back());
                a[4].pop_back();
            } else no();
        } else if(sz(x) == 1) {
            if(sz(a[1])) {
                for(pii y: x) {
                    ans[y.fi][y.se] = a[1].back();
                }
                a[1].pop_back();
            } else if(sz(a[2])) {
                for(pii y: x) {
                    ans[y.fi][y.se] = a[2].back();
                }
                a[1].emplace_back(a[2].back());
                a[2].pop_back();
            } else if(sz(a[4])) {
                for(pii y: x) {
                    ans[y.fi][y.se] = a[4].back();
                }
                a[1].emplace_back(a[4].back());
                a[2].emplace_back(a[4].back());
                a[4].pop_back();
            } else no();
        } else assert(false);

        // watch(sz(x))
        // for(pii y: x) {
        //     cerr << y.fi << "," << y.se << endl;
        // }
        // cerr << endl;
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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
