// https://codeforces.com/contest/1292/problem/A

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

const int maxn = 100500;
int n, q;
int cur = 0;
bool blocked[2][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= q; i++) {
        int r, c;
        cin >> r >> c;
        r--;

        int pre = (blocked[r][c] and blocked[r^1][c]) + (blocked[r][c] and blocked[r^1][c-1]) + (blocked[r][c] and blocked[r^1][c+1]);

        blocked[r][c] ^= 1;

        int now = (blocked[r][c] and blocked[r^1][c]) + (blocked[r][c] and blocked[r^1][c-1]) + (blocked[r][c] and blocked[r^1][c+1]);

        cur -= pre;
        cur += now;
        
        watch(pre)
        watch(now)
        watch(cur)
        for(int j = 0; j <= 1; j++) {
            for(int k = 1; k <= n; k++) {
                cerr << blocked[j][k] << " ";
            }
            cerr << endl;
        }
        if(cur == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cerr << endl;
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
