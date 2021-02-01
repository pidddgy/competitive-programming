// https://codeforces.com/contest/1388/problem/D

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

int n;
int a[maxn], b[maxn];
bool vis[maxn];

vector<int> topo;

void dfs(int v) {
    vis[v] = true;
    if(b[v] != -1 and !vis[b[v]]) {
        dfs(b[v]);
    }

    topo.push_back(v);
}

int dp[maxn];
int ans = 0;
vector<int> out;

void f(int ind) {
    if(ind == n+1) return;
    int i = topo[ind];
    ans += a[i];

    // push down first
    if(a[i] >= 0 and b[i] != -1) {
        out.emplace_back(i);
        a[b[i]] += a[i];
        f(ind+1);
    } else {
        f(ind+1);
        out.emplace_back(i);

        if(b[i] != -1) {
            a[b[i]] += a[i];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];        
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];

        if(b[i] != -1) {
            cerr << i << " " << b[i] << endl;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    // make topo 1 indexed
    topo.push_back(0);
    reverse(all(topo));

    f(1);

    cout << ans << endl;
    for(int x: out) {
        cout << x << " ";
    }
    cout << endl;
}

/*

directed acyclic graph, toposort
dp[i] = max possible value i can be before pushing down

for i in nodes toposroted
    add a[i] to ans
    if a[i] is positive then push this down before pushing down its child
    otherwise push down its child and do all of children operations, then push this one down

an operation is "pushign down"

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
