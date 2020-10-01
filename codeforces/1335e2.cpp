// https://codeforces.com/problemset/problem/1335/E2

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #pragma GCC optimize "Ofast"
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

const int maxn = 2e5+50;
const int maxv = 250;

int n;
int a[maxn];
int psa[maxv][maxn];
vector<int> pos[maxv];

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 200; j++) psa[j][i] = psa[j][i-1];

        psa[a[i]][i]++;
        pos[a[i]].emplace_back(i);
    }

    for(int i = 1; i <= 200; i++) sort(all(pos[i]));

    int ans = 1;
    for(int i = 1; i <= 200; i++) {
        for(int j = 1; j <= pos[i].size(); j++) {
            int l = pos[i][j-1], r = pos[i][sz(pos[i])-j];

            if(l > r-1) break;

            for(int k = 1; k <= 200; k++) {
                // in between
                int sum = psa[k][r-1] - psa[k][l];

                ans = max(ans, sum + 2*j);
            }
        }
    }

    cout << ans << endl;

    for(int i = 1; i <= n; i++) {
        a[i] = 0;
    }

    for(int i = 1; i <= 200; i++) {
        for(int j = 1; j <= n; j++) {
            psa[i][j] = 0;
        }
        pos[i].clear();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

let A = max value

observations
    - a[i] is small
    - n*a[i] == 40 000 000
    - subsequence, not subarray

naive solution N * (A^2)
    iterate over all possible outers
        brute force from 1...n "take i outside" using pos array or whatever
            iterate over all possible inners and take max with psa

ds bash time

keep track of all positions of each element

for each possible element value
    for i in whatever
        take leftmost and rightmost i elements
        if the remainder is valid(ith rightmost > ith leftmost)
        push into query, add 2i as a value

store queries as pair int int 

m o s algo ri th m / sqrt decomp
    - https://cp-algorithms.com/data_structures/sqrt_decomposition.html

use map<int, int> and set<pii>
    - might need some custom compare for set

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
