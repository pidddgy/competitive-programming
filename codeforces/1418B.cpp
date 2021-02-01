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

const int maxn = 105;

int n;
int a[maxn];
int l[maxn];
void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> v;

    for(int i = 1; i <= n; i++) {
        cin >> l[i];

        if(l[i] == 0) v.emplace_back(a[i]);
    }

    sort(all(v));

    for(int i = 1; i <= n; i++) {
        if(l[i] == 0) {
            a[i] = v.back();
            v.pop_back();
        }

        cout << a[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
