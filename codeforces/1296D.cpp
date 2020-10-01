// https://codeforces.com/contest/1296/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

int n, a, b, k;
int h[maxn];
int cost[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> k;

    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for(int i = 1; i <= n; i++) {
        int rem;
        int l = 0, r = 1e9;

        while(l <= r) {
            int md = (l+r)/2;

            // cerr << "trying " << md << endl;
            if(md*(a+b) < h[i]) {
                // cerr << "good" << endl;
                rem = h[i]-(md*(a+b));
                l = md+1;
            } else {
                r = md-1;
            }
        }

        watch(rem)

        cost[i] = ((rem+a-1)/a)-1;
        cerr << cost[i] << endl;
    }    
    cerr << endl;

    sort(cost+1, cost+n+1);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(cost[i] <= k) {
            k -= cost[i];
            ans++;
        }
    }

    cout << ans << endl;
}

/*

take residue mod a+b

if residue <= a we can get it for free

otherwise
    find rem
    we have to make the other person skip ((rem+a-1)/a)-1 times
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
