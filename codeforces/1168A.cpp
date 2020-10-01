// https://codeforces.com/contest/1168/problem/A

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

int n, m;
int a[maxn];

bool f(int x) {
    int pre = 0;
    for(int i = 1; i <= n; i++) {
        if(pre <= a[i]) {
            // try to make a[i] loop back around to pre
            int cost = (m - a[i]) + pre;

            // if impossible
            if(cost > x) {
                pre = a[i];
            }
        } else {
            int cost = pre-a[i];

            if(cost > x) return false;
        }
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 0, r = m;
    int lgood = -1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(f(mid)) {
            lgood = mid;
            r = mid-1;
        } else {
            l = mid+1;        
        }
    }

    assert(lgood != -1);

    cout << lgood << endl;
}

/*

upper bound: make them all 0 so sum of m-a[i] for all i from 1..N



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
