// https://codeforces.com/contest/883/problem/G

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

const int maxn = 300500;

bool reachable[maxn];
vector<int> G[maxn];
vector<pii> Gp[maxn];
bool vis[maxn];

void cl() {
    for(int i = 0; i < maxn; i++) {
        vis[i] = false;
    }
}
int n, m, s;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s;    

    int un = 0;
    for(int i = 1; i <= m; i++) {
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 1) {
            G[u].emplace_back(v);
        } else {
            un++;
            Gp[u].emplace_back(v, un);
            Gp[v].emplace_back(u, -un);
        }
    }

    string ans1;

    queue<int> Q;
    Q.push(s);
    vis[s] = true;
    
    map<int, char> ans;
    for(int i = 1; i <= un; i++) ans[i] = '-';
    int tot = 0;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        tot++;

        for(int to: G[S]) {
            if(!vis[to]) {
                vis[to] = true;
                Q.push(to);
            }
        }

        for(pii to: Gp[S]) {
            if(!vis[to.fi]) {
                vis[to.fi] = true;
                Q.push(to.fi);

                if(to.se > 0) ans[to.se] = '+';
                else ans[-to.se] = '-';
            }
        }
    }

    cout << tot << endl;
    for(int i = 1; i <= un; i++) {
        cout << ans[i];
    }
    cout << endl;
    // ~~~~~

    cl();
    tot = 0;
    Q.push(s);
    vis[s] = true;

    for(int i = 1; i <= un; i++) ans[i] = '-';
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        tot++;

        for(int to: G[S]) {
            if(!vis[to]) {
                vis[to] = true;
                Q.push(to);
            }
        }

        for(pii to: Gp[S]) {
            if(to.se > 0) ans[to.se] = '-';
            else ans[-to.se] = '+';
        }
    }

    cout << tot << endl;
    for(int i = 1; i <= un; i++) {
        cout <<ans[i];
    }
    cout << endl;

}

/*

bool reachable[n]

sort edges on if they're reachable, 

if both sides reachable it doens't matter
if one side is reachable we can bridge or not bridge



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
