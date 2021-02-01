// https://cses.fi/problemset/task/1094

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

const int maxn = 200500;

int n;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0; 
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        if(i == 1) continue;

        if(a[i] <= a[i-1]) {
            ans += a[i-1]-a[i];

            a[i] = a[i-1];
        }
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
