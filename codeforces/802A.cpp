// https://codeforces.com/contest/802/problem/A

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

const int maxn = 100;

int n, k;
int a[maxn];
set<int> S;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(S.count(a[i])) continue;
        cerr << "incrementing on " << i << endl;
        ans++;

        if(sz(S) == k) {
            int rem = -1, ma = INT_MIN;

            for(int x: S) {
                int nxt = LLONG_MAX;

                for(int j = i+1; j <= n; j++) {
                    if(a[j] == x) {
                        nxt = j;
                        break;
                    }
                }

                if(ma < nxt) {
                    ma = nxt;
                    rem = x;
                }
            }

            S.erase(rem);
        }

        S.emplace(a[i]);
    }

    cout << ans << endl;
}

/*

always erase the one that we need last

exchange: we need to use both the element being erased and the element being added anyway. by swapping the two our solution never gets worse, but there are cases where it gets better. in the case that the element we remove is not present later then it becomes obvious that we should remove that element.

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
