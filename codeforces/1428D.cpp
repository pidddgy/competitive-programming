// https://codeforces.com/contest/1428/problem/D

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

const int maxn = 100500;

int n;
int a[maxn], to[maxn];
vector<int> v[5];
bool vis[maxn];

void no() {
    cout << -1 << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = n; i >= 1; i--) {
        if(a[i] == 0) continue;

        if(a[i] == 1) {
            v[1].emplace_back(i);
        } else if(a[i] == 2) {
            if(v[1].empty()) no();

            to[i] = v[1].back();
            v[1].pop_back();

            v[2].emplace_back(i);
        } else if(a[i] == 3) {
            if(sz(v[3])) {
                to[i] = v[3].back();
                v[3].pop_back();
            } else if(sz(v[2])) {
                to[i] = v[2].back();
                v[2].pop_back();
            } else if(sz(v[1])) {
                to[i] = v[1].back();
                v[1].pop_back();
            } else no();
            v[3].emplace_back(i);
        }
    }

    for(int i = 1; i <= n; i++) {
        cerr << to[i] << " ";
    }
    cerr << endl;

    int row = 1;
    vector<pii> ans;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0 or vis[i]) continue;

        cerr << "starting chain from " << i << endl;
        // process chains
        int col = i;
        while(col != 0) {
            vis[col] = true;

            if(a[col] == 1) {
                ans.emplace_back(row, col);
                row++;
                break;
            } else if(a[col] == 2) {
                ans.emplace_back(row, col);
                col = to[col];
            } else if(a[i] == 3) {
                ans.emplace_back(row, col);
                col = to[col];
                ans.emplace_back(row, col);
                row++;
            }
        }
    }

    cout << sz(ans) << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}

/*

iterate from right -> left

0s get ignored
1s do not get matched
2s get matched to 1, and then tht 1 canot be used for anything else
3 can be matched to 1(cannot use 1 for anythign else), or chained to 2 or 3

when iterate do current column and the links

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
