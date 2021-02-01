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

const int maxn = 100500;

int a[maxn];
int mi[maxn];
int sum[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    mi[n+1] = 1e18;
    for(int i = n; i >= 1; i--) {
        mi[i] = min(a[i], mi[i+1]);
        sum[i] = sum[i+1]+a[i];
    }

    ld ma = 0;

    for(int i = 1; i <= n-2; i++) {
        int rem = n-i-1;
        ld avg = (sum[i+1]-mi[i+1])/(ld)rem;

        cerr << i << endl;
        watch(avg)
        watch(sum[i+1])
        watch(mi[i+1])
        watch(rem)
        if(avg > ma) {
            ma = avg;
        } 
    }

    watch(ma)
    for(int i = 1; i <= n-2; i++) {
        int rem = n-i-1;
        ld avg = (sum[i+1]-mi[i+1])/(ld)rem;

        if(avg == ma) {
            cout << i << endl;
        }
    }
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
