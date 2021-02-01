// https://codeforces.com/contest/1012/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

const int maxn = 5005;

int n;
int a[maxn];

int dp[maxn/2][maxn];
int pre[maxn/2][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[0] = a[n+1] = -300;

    for(int i = 0; i < maxn/2; i++) {
        for(int j = 0; j < maxn; j++) {
            dp[i][j] = pre[i][j] = 1e12;
        }
    }

    for(int j = 1; j <= n; j++) {
        dp[1][j] = 0;
        dp[1][j] += max(0LL, a[j+1]-(a[j]-1));
        dp[1][j] += max(0LL, a[j-1]-(a[j]-1));

        pre[1][j] = min(pre[1][j-1], dp[1][j]);
    }
    
    assert(pre[1][n] != 1e12);
    cout << pre[1][n] << " ";

    for(int i = 2; i <= (n+1)/2; i++) {
        for(int j = 1; j <= n; j++) {
            if(j >= 3) {
                // transition from j-2
                int cost = dp[i-1][j-2];
                int cur = min(a[j-1], a[j-2]-1);
                int to = a[j]-1;
                cost += max(0LL, cur-to);
                cost += max(0LL, a[j+1]-(a[j]-1));

                dp[i][j] = min(dp[i][j], cost);
            }

            if(j >= 4) {
                cerr << "on " << i << " " << j << endl;
                // transition from j-3
                int cost = pre[i-1][j-3];
                int to = a[j]-1;

                watch(cost);
                watch(to)
                cost += max(0LL, a[j-1]-to);
                cost += max(0LL, a[j+1]-to);

                dp[i][j] = min(dp[i][j], cost);
            }

            pre[i][j] = min(pre[i][j-1], dp[i][j]);
        }

        cout << pre[i][n] << " ";
        assert(pre[i][n] != 1e12);
    }
    cout << endl;

    watch(dp[1][1])
    watch(pre[1][6])
    watch(dp[2][9])
}

/*

dp[hills made][last hill]

if last hill = i-1, impossible
if i-2, then i-1 has already been reduced some amount
if <= i-3 then it doesnt matter

remember to take into account i+1



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
