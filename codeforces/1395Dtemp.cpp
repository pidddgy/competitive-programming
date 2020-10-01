// Link

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

int n, d, m;

// a <= m, b > m
vector<int> a, b;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> m;

    for(int i = 1; i <= n; i++) {
        int v;
        cin >> v;

        if(v <= m) {
            a.emplace_back(v);
        } else {
            b.emplace_back(v);
        }
    }

    // get lengths before 1 indexing
    int alen = sz(a);
    int blen = sz(b);

    int dp[sz(a)+5][sz(b)+5];
    for(int i = 0; i < sz(a)+5; i++) {
        for(int j = 0; j < sz(b)+5; j++) {
            dp[i][j] = 0;
        }
    }

    // make them 1 indexed
    a.emplace_back(-500);
    b.emplace_back(INT_MAX);

    sort(all(a));
    sort(all(b), greater<int>());

    for(int i = 0; i <= alen; i++) {
        for(int j = 0; j <= blen; j++) {
            // pick an element from b
            if(j) {
                dp[i][j] = max(dp[i][j], dp[max(0LL, i-d)][j-1] + b[j]);
            }
            
            if(i) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i]);
            }

            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    watch(dp[0][1])
    watch(dp[3][1])


    cout << dp[alen][blen] << endl;
}

/*

on each day we get muted or not muted (we can biject list into <= m and > m), call them a and b

by picking any factor > m, we are losing out on the next d smallest

(sort a and b
dp[i][j] = maximum we can get using the first i elements of a, first j elements of b
transition from dp[i-d][j-1] or dp[i-1][j])
    ^ invalidated because sorting is not always correct
    wait is it




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
