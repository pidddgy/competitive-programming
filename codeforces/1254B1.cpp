// https://codeforces.com/contest/1254/problem/B1

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        cur += x;

        // if()
    }
}

/*

observation: we should pick a prime number as k

the total sum has to be divisible by this number, so we can brute force

subproblem: how can we separate them into groups of x

since they are only 1, we can look at grouping little "runs" with have sum k

we can brute force prefix/suffix for each run

brute force again to find the best point

this runs in o(n) because we process each run separately




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
