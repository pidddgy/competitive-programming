// https://codeforces.com/contest/917/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pic pair<int, char>
#define fi first
#define se second

const int maxn = 105;

int n, m;

// dp[current max alphabet][position][opponent position]. 0 = lose, 1 = win, '?' = not sure
int dp[26][maxn][maxn];
set<pic> G[maxn];

int dfs(char chr, int pos, int opos) {
    if(dp[chr-'a'][pos][opos] != '?') {
        return dp[chr-'a'][pos][opos];
    }
    
    bool winning = false;
    for(pic adj: G[pos]) {
        if(adj.se >= chr) {
            if(dp[adj.se-'a'][opos][adj.fi] == '?') {
                dfs(adj.se, opos, adj.fi);
            }

            if(dp[adj.se-'a'][opos][adj.fi] == 0) {
                winning = true;
            }
        }
    }

    return dp[chr-'a'][pos][opos] = winning;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < maxn; j++) {
            for(int k = 0; k < maxn; k++) {
                dp[i][j][k] = '?';
            }
        }
    }

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;

        G[u].emplace(v, c);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dfs('a', i, j)) {
                cout << 'A';
            } else {
                cout << 'B';
            }
        }
        cout << endl;
    }   
}
