// https://codeforces.com/contest/986/problem/B

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

const int maxn = (int)1e6+5;

int a[maxn];
bool vis[maxn];

void dfs(int v) {
    vis[v] = true;
    if(!vis[a[v]]) {
        dfs(a[v]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int swaps = n;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            swaps--;
        }
    }

    if(swaps%2 == n%2) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
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
