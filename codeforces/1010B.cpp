// https://codeforces.com/contest/1010/problem/B

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

const int maxn = 35;

int p[maxn];
signed main() {
    int m, n;
    cin >> m >> n;

    for(int i = 1; i <= n; i++) {
        cout << 1 << endl;

        int res;
        cin >> res;

        if(res == 0) {
            exit(0);
        } else if(res == 1) {
            p[i] = 1;
        } else if(res == -1) {
            p[i] = 0;
        }
    }

    int l = 1;
    int r = m;
    int cur = 1;

    for(int i = 1; i <= 60-n; i++) {
        int md = (l+r)/2;

        cout << md << endl;

        int res;
        cin >> res;

        if(res == 0) {
            exit(0);
        } else if(res == 1) {
            if(p[cur]) {
                l = md+1;
            } else {
                r = md-1;
            }
        } else if(res == -1) {
            if(p[cur]) {
                r = md-1;
            } else {
                l = md+1;
            }
        }

        cur++;
        if(cur == n+1) cur = 1;
    }

    assert(l == r);

    cout << l << endl;
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
