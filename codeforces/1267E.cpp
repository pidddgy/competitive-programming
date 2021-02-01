// https://codeforces.com/problemset/problem/1267/E

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

const int maxn = 105;

int n, m;
int a[maxn][maxn];
pii b[maxn];

vector<int> go(int x) {
    cerr << "trying " << x << endl;
    int cur = 0;
    for(int i = 1; i <= m; i++) {
        b[i].fi = (a[i][x]-a[i][n]);
        cur += b[i].fi;
        b[i].se = i;
    }

    sort(b+1, b+m+1);
    watch(cur)
    for(int i = 1; i <= m; i++) {
        cerr << b[i].fi << " " << b[i].se << endl;
    }
    if(cur >= 0) {
        cout << 0 << endl;
        exit(0);
    }

    vector<int> ans;
    for(int i = 1; i <= m; i++) {
        cur -= b[i].fi;
        ans.emplace_back(b[i].se);

        if(cur >= 0) break;
    }

    watch(sz(ans))
    cerr << endl;

    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cur = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> out;
    for(int i = 1; i <= n-1; i++) {
        // ans = min(ans, go(i));
        vector<int> loc = go(i);
        if(sz(loc) < sz(out) or out.empty()) {
            out = loc;
        }
    }

    cout << sz(out) << endl;
    for(int o: out) {
        cout << o << " ";
    }
    cout << endl;
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
