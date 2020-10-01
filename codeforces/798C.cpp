// https://codeforces.com/problemset/problem/798/C

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
int a[maxn], dp[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int g = 0;
    int cnt = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        g = __gcd(a[i], g);

        cnt += a[i] & 1;

        if(a[i]%2==0) {
            ans += (cnt/2) + 2*(cnt%2);  
            cnt = 0;
        }
    }
    ans += (cnt/2) + 2*(cnt%2);  

    cout << "YES" << endl;
    if(g != 1) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

    
}

/*

always possible because we can make everything even

the difference gets x2'ed

worst case per each element:
    -> (odd, even)
    -> (odd, odd)
    -> (even, even)

upper bound is 2*n

countercase for "make everything even":
    3 10 4



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
