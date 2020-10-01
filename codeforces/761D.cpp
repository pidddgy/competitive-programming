// https://codeforces.com/contest/761/problem/D

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

void no() {
    cout << -1 << endl;
    exit(0);
}
const int maxn = 100500;

int a[maxn], p[maxn], ans[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<pii> inds;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        inds.emplace_back(p[i], i);
    }
    sort(inds.begin(), inds.end());

    int last = -1e9;
    for(pii x: inds) {
        int c = last+1;
        int b = max(l, c+a[x.se]);

        if(b > r) {
            no();
        }

        ans[x.se] = b;
        last = b-a[x.se];
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

go in order of p[i]

make every single element as small as possible while still being above last element

last
desired element in c = last+1

let cur = a

max(l, desired+a)

if above r then invalid

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
