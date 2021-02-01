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

const int maxn = 350;
int n, m;

int a[maxn];
int l[maxn], r[maxn];

int go(int dec, int oth) {
    int res = a[oth]-a[dec];
    cerr << dec << " " << oth << endl;
    watch(res)
    for(int i = 1; i <= m; i++) {
        if(l[i] <= dec and dec <= r[i]) {
            if(!(l[i] <= oth and oth <= r[i])) {
                res++;
            }
        }
    }
    watch(res)

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }

    int best = -(1e18);
    pii inds = {0, 0};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;

            // go(i, j);
            if(go(i, j) > best) {
                best = go(i, j);
                inds = pii(i, j);
            }
        }
    }

    vector<int> ans;
    int dec = inds.fi, oth = inds.se;
    int res = a[oth]-a[dec];
    for(int i = 1; i <= m; i++) {
        if(l[i] <= dec and dec <= r[i]) {
            if(!(l[i] <= oth and oth <= r[i])) {
                // ans.emplace_back(l[i], r[i]);
                ans.emplace_back(i);
                res++;
            }
        }
    }

    cout << go(dec, oth) << endl;
    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;

}

/*
27 000 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
