// https://codeforces.com/contest/813/problem/C

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

const int maxn = 200500;
vector<int> G[maxn];
int disa[maxn], disb[maxn];
int n, x;

void bfs(int st, int arr[]) {
    queue<int> Q;
    Q.push(st);
    arr[st] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        for(int to: G[S]) {
            if(to != 1 and arr[S]+1 < arr[to]) {
                Q.push(to);
                arr[to] = arr[S]+1;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        disa[i] = disb[i] = INT_MAX-500;
    }

    cin >> n >> x;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    bfs(1, disa);
    bfs(x, disb);
    
    for(int i = 1; i <= n; i++) {
        cerr << disa[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        cerr << disb[i] << " ";
    }
    cerr << endl;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(disb[i] < disa[i]) ans = max(ans, disa[i]*2);
    }

    cout << ans << endl;
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
