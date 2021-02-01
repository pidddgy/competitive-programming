// https://dmoj.ca/problem/dmopc20c1p2

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

const int maxn = (int)1e6+5;

int a[maxn], psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
    }

    int l = 1, r = n;
    for(int i = 1; i <= d; i++) {
        int x;
        cin >> x;

        int f = psa[l+x-1]-psa[l-1];
        int s = psa[r]-psa[l+x-1];

        cerr << f << " " << s << endl;

        if(f >= s) {
            l += x;
        } else {
            r = l+x-1;
        }

        cerr << "setting l to " << l << " r to " << r << endl;

        cout << max(f, s) << endl;
    }
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
