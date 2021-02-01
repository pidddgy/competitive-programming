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

int n;
int getma(vector<int> a, vector<int> b) {
    int cur = 0;
    for(int i = 0; i < n; i++) {
        while(cur < n and b[cur] < a[i]) cur++;
        if(cur == n) return i;

        cur++;
    }

    return n;
}

void solve() {
    cin >> n;
    vector<int> b, nb;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        b.emplace_back(x);
    }

    for(int i = 1; i <= 2*n; i++) {
        if(!binary_search(all(b), i)) {
            nb.emplace_back(i);
        }
    }

    for(int x: b) {
        cerr << x << " ";
    }
    cerr << endl;

    for(int x: nb) {
        cerr << x << " ";
    }
    cerr << endl;

    int ma = getma(b, nb);
    int mi = n-getma(nb, b);

    cerr << ma << " " << mi << endl;

    cout << ma-mi+1 << endl;
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
