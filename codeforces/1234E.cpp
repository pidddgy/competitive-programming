// https://codeforces.com/contest/1234/problem/E

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

int pos(int p, int x_i) {
    if(p == x_i) return 1;
    if(x_i < p) return x_i+1;
    return x_i;
}

int ans[maxn];

// difference array
void upd(int l, int r, int val) {
    if(l > r) return;

    ans[l] += val;
    ans[r+1] -= val;
}

int n, m;
int x[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // watch(pos(1, 3))
    // watch(pos(2, 2))
    // watch(pos(4, 4))

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        cin >> x[i];
    }

    for(int i = 1; i <= m-1; i++) {
        cerr << "on " << i << endl;
        int mi = min(x[i], x[i+1]);
        int ma = max(x[i], x[i+1]);

        int a = pos(mi-1, mi);
        int b = pos(mi-1, ma);
        upd(1, mi-1, abs(a-b));
        cerr << "add " << abs(a-b) << " to " << 1 << " " << mi-1 << endl;

        a = pos(mi, mi);
        b = pos(mi, ma);  
        upd(mi, mi, abs(a-b));
        cerr << "add " << abs(a-b) << " to " << mi << " " << mi << endl;

        a = pos(mi+1, mi);
        b = pos(mi+1, ma);
        upd(mi+1, max(mi+1, ma-1), abs(a-b));
        cerr << "add " << abs(a-b) << " to " << mi+1 << " " << max(mi+1, ma-1) << endl;

        if(mi+1 != ma) {
            a = pos(ma, mi);
            b = pos(ma, ma);
            upd(ma, ma, abs(a-b));
            cerr << "add " << abs(a-b) << " to " << ma << " " << ma << endl;
        }

        a = pos(ma+1, mi);
        b = pos(ma+1, ma);
        upd(ma+1, n, abs(a-b));
        cerr << "add " << abs(a-b) << " to " << ma+1 << " " << n << endl;

        cerr << endl;
    }

    for(int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

for position of element x in any p_i
    if(x == i) -> 1
    if(x < i) -> x+1
    else x

for any pair i, j segments 1...j, i+1...j-1, j...m are all the same

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
