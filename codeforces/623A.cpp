// https://codeforces.com/contest/623/problem/A

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

const int maxn = 505;

bool adj[maxn][maxn];
vector<int> G[maxn];

int n, m;
char ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        ans[i] = '?';
    }

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
        adj[u][v] = adj[v][u] = true;
    }

    for(int i = 1; i <= n; i++) {
        if(sz(G[i]) == n-1) {
            ans[i] = 'b';
        }
    }

    for(int i = 1; i <= n; i++) {
        if(ans[i] == '?') {
            queue<int> Q;
            Q.push(i);

            while(sz(Q)) {
                int S = Q.front(); Q.pop();
                ans[S] = 'a';

                for(int to: G[S]) {
                    if(ans[to] == '?') {
                        Q.push(to);
                    }
                }
            }
            break;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(ans[i] == '?') {
            ans[i] = 'c';
        }
    }

    bool valid = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;

            bool ok = true;

            if(adj[i][j]) {
                if(!(abs(ans[i]-ans[j]) <= 1)) {
                    ok = false;
                }
            } else {
                if(abs(ans[i]-ans[j]) != 2) {
                    ok = false;
                }
            }

            if(!ok) valid = false;
        }
    }

    if(valid) {
        cout << "Yes" << endl;
        for(int i = 1; i <= n; i++) {
            cout << ans[i];
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
}

/*

three components in graph
~

5 4
1 2
2 3
3 4
4 5

1 = a
2 = a
3 = b
4 = c
5 = invalid

~

3 3
1 2
1 3
2 3

1 = a
2 = a
3 = b

~

4 5
1 2
2 3
3 4
4 1
1 3

1 = b
2 = a
3 = b
4 = c



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
