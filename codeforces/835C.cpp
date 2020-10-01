// https://codeforces.com/problemset/problem/835/C

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

const int maxc = 15;
const int maxn = (int)1e5+100;
const int maxcoord = 105;

int n, q, c;
int x[maxn], y[maxn], s[maxn];
int psa[maxc][maxcoord][maxcoord];

int query(int t, int i, int j, int ii, int jj) {
    return psa[t][ii][jj] - psa[t][ii][j-1] - psa[t][i-1][jj] + psa[t][i-1][j-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q >> c;

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];

        for(int j = 0; j <= c; j++) {
            psa[j][x[i]][y[i]] += (s[i]+j)%(c+1);
        }
    }

    for(int i = 0; i <= c; i++) {
        for(int j = 1; j <= 100; j++) {
            for(int k = 1; k <= 100; k++) {
                psa[i][j][k] += psa[i][j-1][k] + psa[i][j][k-1] - psa[i][j-1][k-1];
            }
        }
    }

    while(q--) {
        int t, x_1, y_1, x_2, y_2;

        cin >> t >> x_1 >> y_1 >> x_2 >> y_2;

        cout << query(t%(c+1), x_1, y_1, x_2, y_2) << endl;
    }
}

/*


take all brightness mod c+1

calculate 2d psa for every single possible residue
query by doing time mod c+1


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
