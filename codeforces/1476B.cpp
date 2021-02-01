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


int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

void solve() {
    int n, k;
    cin >> n >> k;

    int cur;
    cin >> cur;

    int rt = k;
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        
        int l = 0, r = 1e14;
        int lgood = 0;

        while(l <= r) {
            int mid = (l+r)/2;

            int lc = lcm(100, cur+mid);
            int num1 = x*(lc/(cur+mid));
            int num2 = rt*(lc/100);

            if(num1 <= num2) {
                lgood = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        ans += lgood;
        cur += lgood;
        cur += x;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

inflate biggest element
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?