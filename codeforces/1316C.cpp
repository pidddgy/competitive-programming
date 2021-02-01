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

const int maxn = 1e6+500;

int a[maxn];
int b[maxn];
int c[3*maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        if(a[i] % p ) {
            ans += i;
            break;
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < m; i++) {
        if(b[i]% p) {
            ans += i;
            break;
        }
    }

    cout << ans << endl;
}

/*

a[0]*b[1] + a[1]*b[0]
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
