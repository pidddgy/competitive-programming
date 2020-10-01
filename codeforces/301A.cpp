// https://codeforces.com/contest/301/problem/A

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


int a[500];
bool vis[500];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int len = 2*n-1;
    int neg = 0;
    for(int i = 1; i <= len; i++) {
        cin >> a[i];
        if(a[i] < 0) neg++;

        a[i] = abs(a[i]);
    }

    sort(a+1, a+len+1);

    queue<int> Q;
    Q.push(neg);

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        watch(S)
        vis[S] = true;
        neg = min(neg, S);

        // how many negatives are we turning into positive
        for(int i = 1; i <= min(n, S); i++) {
            // how many positives are we turning into negatives
            int pos = n-i;

            int to = S-i+pos;

            cerr << i << " results in " << to << endl;

            if(!vis[to] and to <= len) {
                Q.push(to);
            }
        }
    }

    watch(neg)

    int ans = 0;
    for(int i = 1; i <= len; i++) {
        if(i <= neg) ans -= a[i];
        else ans += a[i];
    }

    cout << ans << endl;
}

/*

bfs on negatives needed at any time

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
