// https://codeforces.com/contest/909/problem/E

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

void solve() {
    
}

const int maxn = 100500;

int n, m;
vector<int> G[maxn];
int a[maxn], dep[maxn];
vector<int> S[2];
bool vis[maxn];

int done = 0;

// do all 0 or 1 tasks
void go(int type) {
    vector<int> emp[2];
    while(sz(S[type])) {
        int cpy = S[type].back();
        S[type].pop_back();
        for(int to: G[cpy]) {
            if(dep[to] and !vis[to]) {
                dep[to]--;
                if(dep[to] == 0) {
                    S[a[to]].emplace_back(to);
                    vis[to] = true;
                }
            }
        }

        done++;
        assert(done <= n);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        G[v].emplace_back(u);
        dep[u]++;
    }

    for(int i = 0; i < n; i++) {
        if(dep[i] == 0) {
            S[a[i]].emplace_back(i);
            vis[i] = true;
        }
    }

    int ans = 0;
    while(done < n) {
        if(S[0].empty()) {
            go(1);
            ans++;
        } else {
            go(0);
        }
    }

    cout << ans << endl;
}

/*

processor calls are free

maintain dependencies each task has
maintain set of processor and coprocessor tasks with no dependencies

when possible do processor, else clear all coprocessor

reverse all edges

<3

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
