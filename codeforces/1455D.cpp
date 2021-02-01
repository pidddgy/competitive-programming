// https://codeforces.com/contest/1455/problem/D

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

// is sorted
bool f(vector<int> v) {
    for(int i = 0; i < sz(v)-1; i++) {
        if(v[i] > v[i+1]) return false;
    }
    return true;
}
int solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(f(a)) return ans;

        if(a[i] > x) {
            swap(a[i], x);
            ans++;
        }

        if(f(a)) return ans;
    }

    return -1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cout << solve() << endl;
    }
}

/*


considering i

lower
must go down on this one no matter what

all same
would fulfill is_sorted

higher
must have one lower in order to fulfill !(is sorted)
if we swap the higher element with x it won't work

realize that we can't reverse operations

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
