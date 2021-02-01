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

int n, k;
int a[maxn];
set<int> S[maxn];
int x[maxn], y[maxn];
bool vis[maxn];

void go() {
    for(int i = 1; i <= k; i++) {

        S[a[x[i]]].emplace(x[i]);

        swap(a[x[i]], a[y[i]]);

        S[a[x[i]]].emplace(x[i]);
        S[a[y[i]]].emplace(y[i]);
    }
}

int ans[maxn];
int par[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        a[i] = i;
        S[i].emplace(i);
    }

    for(int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i];
    }

    go();

    vector<pii> v;
    for(int i = 1; i <= n; i++) {
        v.emplace_back(sz(S[i]), i);
        ans[i] = sz(S[i]);
    }

    for(int st = 1; st <= n; st++) {
        if(vis[st]) continue;

        queue<int> Q;
        Q.push(st);

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            par[cur] = st;
            if(!vis[a[cur]]) {
                vis[a[cur]] = true;
                Q.push(a[cur]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int x: S[i]) S[par[i]].emplace(x);
    }

    for(int i = 1; i <= n; i++) {
        cout << sz(S[par[i]]) << endl;
    }
}

/*

5
1 2
2 3
3 4
4 5


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
