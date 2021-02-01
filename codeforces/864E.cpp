// https://codeforces.com/contest/864/problem/E

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

struct item {
    int t, d, p, ind;

    item() {
        t = 0;
        d = 0;
        p = 0;
        ind = 0;
    }
};

bool cmp(item &l, item &r) {
    return l.d < r.d;
}

const int maxn = 105;
const int maxd = 2005;

int n;
int dp[maxn][maxd];
pii par[maxn][maxd];
bool save[maxn][maxd];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    struct item a[maxn];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].d >> a[i].p;
        a[i].ind = i;
    }

    sort(a+1, a+n+1, cmp);

    for(int i = 1; i <= n; i++) {
        cerr << a[i].t << " " << a[i].d << " " << a[i].p << " " << a[i].ind << endl;
    }

    // change when submitting
    int upto = 2000;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= upto; j++) {
            // can save item i
            if(a[i].t <= j and j < a[i].d) {
                if(dp[i-1][j-a[i].t]+a[i].p > dp[i][j]) {
                    par[i][j] = pii(i-1, j-a[i].t);
                    dp[i][j] = dp[i-1][j-a[i].t]+a[i].p;
                    save[i][j] = true;
                } 
            }

            if(dp[i-1][j] > dp[i][j]) {
                dp[i][j] = dp[i-1][j];
                par[i][j] = pii(i-1, j);
                save[i][j] = false;
            }

            if(dp[i][j-1] > dp[i][j]) {
                dp[i][j] = dp[i][j-1];
                par[i][j] = pii(i, j-1);
                save[i][j] = false;
            }

            cerr << save[i][j] << " ";
        }
        cerr << endl;
    }

    vector<int> v;
    pii cur = pii(n, upto);

    while(cur.fi != 0) {
        cerr << "on " << cur.fi << " " << cur.se << endl;
        if(save[cur.fi][cur.se]) {
            v.push_back(a[cur.fi].ind);
        }

        cur = par[cur.fi][cur.se];
    }

    cout << dp[n][upto] << endl;
    reverse(all(v));

    cout << sz(v) << endl;
    for(int x: v) {
        cout << x << " ";
    }
    cout << endl;
}

/*

if d[i] is big then it would be classic knapsack
dpp[i][j] = first i items, j time

check if j <= t[i]

observation: it is always optimal to save items that are about to die first (exchange argument, swap)

think of seconds as money
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
