// https://codeforces.com/contest/1153/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 300100;

int a[maxn], dp[maxn];
vector<int> G[maxn];
int n;
int leaves = 0;

void dfs(int v) {
    if(G[v].size() == 0) {
        dp[v] = 1;
        leaves++;
        return;
    }
    
    int mi = INT_MAX;
    int sum = 0;
    for(int adj: G[v]) {
        dfs(adj);
        sum += dp[adj];
        mi = min(mi, dp[adj]);
    }

    if(a[v]) {
        dp[v] = mi;
    } else {
        dp[v] = sum;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 2; i <= n; i++) {
        int f;
        cin >> f;

        G[f].emplace_back(i);
    }

    dfs(1);

    cout << leaves-dp[1]+1 << endl;
}
