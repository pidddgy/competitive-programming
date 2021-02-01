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

const int maxn = 100500;

int col[maxn], row[maxn];
vector<pii> a[maxn];
void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        col[x]++;
        row[y]++;

        a[x].emplace_back(x, y);
        a[y].emplace_back(x, y);
    }

    set<pii> S;
    for(int i = 1; i <= n; i++) {
        S.emplace(col[i]+row[i], i);
    }

    while(sz(S)) {
        pii p = *S.begin();
        S.erase(S.begin());
        int i = p.se;

        if(col[i] == 1 and row[i] == 0) {
            
            row[i]++;
        }
    }

    



    for(int i = 1; i <= n; i++) {
        col[i] = row[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

guess: answer is <= 2*m

if a rook has row or col open, move to that one





*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
