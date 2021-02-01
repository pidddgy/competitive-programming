// https://codeforces.com/contest/361/problem/D

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

const int maxn = 2005;

int n, k;
int a[maxn];
int dp[maxn];

bool f(int x) {
    for(int i = 0; i < maxn; i++) {
        dp[i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        // change all elemnts from 1..i-1
        dp[i] = i-1;

        for(int j = 1; j < i; j++) {
            // keep j
            if(abs(a[i]-a[j]) <= (i-j)*x) {
                dp[i] = min(dp[i], dp[j] + (i-j-1));
            }
        }

        if((n-i)+dp[i] <= k) return true;
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 0;
    int r = 2e9+50;

    int ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;

        if(f(mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << endl;
}

/*


dp[i] = keep i, min edit

if we could optimize n-i it will be considered in later iterations


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
