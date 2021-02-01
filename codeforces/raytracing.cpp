// https://dmoj.ca/problem/raytracing

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 9050;

int bit[maxn][maxn];
int a[maxn];

void upd(int x, int y, int val) {
    for(int i = x; i <= 9000; i += (i & (-i))) {
        for(int j = y; j <= 9000; j += (j & (-j))) {
            // watch(i)
            // watch(j)
            assert(j != 0);
            bit[i][j] += val;
        }
    }
}

int sum(int r, int c) {
    int res = 0;
    for(int i = r; i >= 1; i -= (i & (-i))) {
        for(int j = c; j >= 1; j -= (j & (-j))) {
            res += bit[i][j];
        }
    }

    return res;
}

int query(int i, int j, int a, int b) {
    return sum(j, b) - sum(i-1, b) - sum(j, a-1) + sum(i-1, a-1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]++;

        upd(a[i], i, 1);
    }

    // watch(query(4, 4, 1, 2));

    int q;
    cin >> q;

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int i, j, a, b;
            cin >> i >> j >> a >> b;
            i++;
            j++;
            a++;
            b++;
            cout << query(a, b, i, j) << endl;
        } else {
            int i, h;
            cin >> i >> h;

            i++;
            h++;

            int oldval = a[i];

            watch(oldval);
            cerr << "updating " << h << " " << i << endl;

            upd(oldval, i, -1);
            upd(h, i, 1);

            a[i] = h;
        }
    }
}

/*


i,a            b



j

d = h-oldval
0 = h-oldval-d

-h = -oldval-d

h = oldval-d



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
