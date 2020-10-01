// https://codeforces.com/problemset/problem/933/A

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

const int maxn = 2050;
int n;
int a[maxn], psa[5][maxn];

int query(int ind, int l, int r) {
    return psa[ind][r] - psa[ind][l-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[a[i]][i]++;
    }

    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= n; j++) {
            psa[i][j] += psa[i][j-1];
        }
    }

    int ans = 0;
    for(int r = n; r >= 1; r--) {
        vector<int> dp(5);
        for(int l = r; l >= 1; l--) {
            cerr << "currently on " << l << " " << r << endl;
            dp[a[l]] = max(dp[a[l]], max(dp[a[l]], dp[a[l]-1])+1);

            watch(dp[1])
            watch(dp[2])

            // 1 + 12 + 2
            ans = max(ans, query(1, 1, l-1) + dp[2] + query(2, r+1, n));

            // 1 + 1 + 2
            ans = max(ans, query(1, 1, r) + query(2, r+1, n));

            // 1 + 2 + 2
            ans = max(ans, query(1, 1, l-1) + query(2, r+1, n));
        }
    }

    // // 1 + 1 + 1 and 2 + 2 + 2
    // for(int i = 1; i <= 2; i++) {
    //     ans = max(ans, query(i, 1, n));
    // }

    cout << ans << endl;
}

/*

can be split into 3 portions, first, the flipped part, last

when we flip a segment

if we use all the 1s in this segment
    first poriton is 1, flipped is 1, last is 1 or 2
if we mix
    first portion is 1, flipped is mixed, last is 2
if we take only 2
    first portion is 1 or 2, flipped is 2, last is 2

mixing the middle is hardest case

first and third are actually subsets of the mix case but with empty portions on the sides

we can iterate and keep track of max length if we end at 1

keep psa
brute force on the middle portion
iterate from right to left because we flip it

for r in N to 1
    for l in i to 1
        update the dp thingy (do the variation where numbers are consecutive)
        either use:
            111.... + 111222 + 2222
            111.... + 111111 + max(1, 2)
            max(1, 2) + 22222 + 22222
        max ans


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
