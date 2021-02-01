// https://codeforces.com/contest/1256/problem/E

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
int dp[maxn], len[maxn], ans[maxn];
pii a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(a+1, a+n+1);

    for(int i = 0; i < maxn; i++) {
        dp[i] = 1e15;
        len[i] = -1;
    }
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 3; j <= 5; j++) {
            if(i >= j) {
                int c = dp[i-j] + (a[i].fi-a[i-j+1].fi);
                if(c < dp[i]) {
                    dp[i] = c;
                    len[i] = j;
                }
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cerr << a[i] << " ";
    // }
    // cerr << endl;

    // for(int i = 1; i <= n; i++) {
    //     cerr << len[i] << " ";
    // }
    // cerr << endl;

    int cur = n;
    int group = 0;
    while(cur > 0) {
        group++;
        for(int i = 0; i < len[cur]; i++) {
            ans[a[cur-i].se] = group;
        }
        // watch(cur)
        cur -= len[cur];
    }

    cout << dp[n] << " " << group << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

if n % 3 == 0 best option is to sort and put into groups of 3
if n % 3 == 1 brute force on which one we put into 

groups are all contiguous

1 2 4
3 5 6

a[4]-a[1] + a[6]-a[3]

vs

a[3]-a[1] + a[6]-a[4]


group sizes are either 3, 4, or 5

1 2 3 4 5 6

a[6] - a[1]

vs

a[3]-a[1] + a[6]-a[4] or a[3]+a[6] - a[1] - a[4]

a[6]-a[1] cancels out and a[3]-a[4] is guaranteed to be non positive

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
