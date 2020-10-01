// https://codeforces.com/contest/1136/problem/D

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

const int MAXN = (int)3e5+69;
vector<int> G[MAXN];
int p[MAXN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
    }

    int ans = 0;
    set<int> S = {p[n]};
    for(int i = n-1; i >= 1; i--) {
        int s = 0;

        for(int x: G[p[i]]) {
            if(S.count(x)) s++;
        }

        if(s == sz(S)) {
            ans++;
        } else {
            S.emplace(p[i]);
        }
    }

    cout << ans << endl;
}

/*

we want nastya to be as high as possible

upper bound: number of students willing to swap with nastya

observation: if a student has to pass through a bunch of students it doesn't really matter what order

when we move a student next to nastya it just ends up shifting the whole thing up by one, and removing the student we used to move nastya up

time complexity: n + e * log2(e)

iterate from right to left, maintaining a set of students we need to pass through

if we encounter a student that is willing to swap with nastya
    check if it is willing to swap with all students in set (if not push into set)
    if it is, add 1 to answer and do not push into set
    otherwise push it into set

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
