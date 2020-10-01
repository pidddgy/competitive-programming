// https://codeforces.com/contest/1148/problem/D

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

const int maxn = 300500;

// pairs[i] = if we want .se as i, what element do we get
// should always be size 1
vector<pii> pairs[2*maxn];
vector<pii> pairs2[2*maxn];

// pairs is used for first case, pairs2 for second case


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        if(a < b) {
            pairs[b].emplace_back(a, i);
            assert(sz(pairs[b]) == 1);
        } else if(a > b) {
            pairs2[b].emplace_back(a, i);
            assert(sz(pairs2[b]) == 1);
        }
    }

    int ans1 = 0, ans2 = 0;
    vector<int> v1, v2;

    int last = INT_MAX;

    for(int i = 6e5; i >= 1; i--) {
        if(sz(pairs[i]) and pairs[i].back().fi < last) {
            last = i;
            ans1++;
            v1.emplace_back(pairs[i].back().se);
            pairs[i].pop_back();
        }
    }

    last = INT_MIN;

    for(int i = 1; i <= 6e5; i++) {
        if(sz(pairs2[i]) and pairs2[i].back().fi > last) {
            last = i;
            ans2++;
            v2.emplace_back(pairs2[i].back().se);
            pairs2[i].pop_back();
        }
    }

    // cout << max(ans1, ans2) << endl;
    if(ans1 > ans2) {
        cout << ans1 << endl;
        for(int x: v1) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << ans2 << endl;
        for(int x: v2) {
            cout << x << " ";
        }
        cout << endl;
    }
}

/*


push pairs into two sets
observation: all numbers are distinct

in the first case:
we always want to maximize the second number, while keeping the first number < the last .se

maintain last .se (init = INF)

for i in 2e5....1
    check if we can have the next .se be i

in the second case:
we always want to minimize the second number, while keeping the first number > the last .se

maintain last .se (init = -INF)

for i in 1....2e5
    check if we can have the next .se be i

take maximum of first and second case

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
