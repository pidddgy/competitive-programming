#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
// #define cerr cout
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

int a[15][15];
bool c[15][15];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int mask = 0; mask <= (1 << (2*n-1))-1; mask++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) c[i][j] = false;
        }
        cerr << bitset<7>(mask) << endl;
        int ind = 0;

        for(int j = 1; j <= n; j++) {
            if(mask & (1 << (ind))) {
                c[1][j] = 1;
            }
            ind++;
        }

        for(int j = 2; j <= n; j++) {
            if(mask & (1 << (ind))) {
                c[j][1] = 1;
            }
            ind++;
        }

        bool bad = false;
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j <= n; j++) {
                int val = c[i-1][j] + c[i][j-1] + c[i-1][j-1];
                if(val == 0 or val == 3) bad = true;

                if(val == 1) c[i][j] = 1;
                else c[i][j] = 0;
            }
        }

        int loc = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cerr << c[i][j] << " ";
                loc += a[i][j]*c[i][j];
            }
            cerr << endl;
        }
        cerr << endl;

        if(!bad)
        ans = max(ans, loc);
    }

    cout << ans << endl;
}

/*

is it optimal to put a cow in 1, 1?

put a cow in 1, 1 and choose any of three neighbours
don't put and choose any two neighbours

cancerous dp

dp[n-1][n-1]
4 choose 2 = 6 possible states

dp[i][j] = consider 1..i and 1..j

there are only 14 possible states of 3x3 grids that follow the restriction

the top and left edge force the state of the whole board

104 857 600

1100010

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
