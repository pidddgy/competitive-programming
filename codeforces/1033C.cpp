// https://codeforces.com/problemset/problem/1033/C

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

const int maxn = 100500;

int a[maxn];

// dp[i] = if is a winning state or not
bool dp[maxn];

int pos[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    // n is a losing state beacuse we have no more moves
    dp[n] = false;

    for(int i = n-1; i >= 1; i--) {
        // if we are connected to a losing state then this is a winning state
        for(int j = pos[i]; j <= n; j += i) {
            if((a[j] > i) and (!dp[a[j]])) {
                dp[i] = true;
            }
        }

        for(int j = pos[i]; j >= 1; j -= i) {
            if((a[j] > i) and (!dp[a[j]])) {
                dp[i] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dp[a[i]]) {
            cout << 'A';
        } else {
            cout << 'B';
        }
    }
    cout << endl;
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
