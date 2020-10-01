// https://codeforces.com/problemset/problem/756/A

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

const int maxn = 200500;

vector<int> G[maxn];

int disj[maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    return disj[v] =findp(disj[v]); 
}

void merge(int a, int b) {
    int c = findp(a), d = findp(b);

    disj[c] = d;
}



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        disj[i] = i;
    }

    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;

        merge(i, p);
    }    

    set<int> S;
    for(int i = 1; i <= n; i++) {
        S.emplace(findp(i));
    }

    int par = 0;
    for(int i = 1; i <= n; i++) {
        int b;
        cin >> b;

        par ^= b;
    }

    int ans = par^1;

    if(sz(S) >= 2) ans += sz(S);
    cout << ans << endl;
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
