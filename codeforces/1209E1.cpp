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

const int maxm = 105;

vector<int> a[maxm];

bool cmp(vector<int> &l, vector<int> &r) {
    return *max_element(all(l)) > *max_element(all(r));
}

int n, m;
int ans = 0;
void f(int cur) {
    if(cur == min(n, m)+1) {
        int loc = 0;
        vector<int> ma(n);
        for(int i = 1; i <= min(n, m); i++) {
            for(int j = 0; j < n; j++) {
                ma[j] = max(ma[j], a[i][j]);
            }
        }

        int sum = accumulate(all(ma), 0);
        ans = max(ans, sum);

        return;
    }

    for(int i = 1; i <= n+1; i++) {
        rotate(a[cur].begin(), a[cur].begin()+1, a[cur].end());

        f(cur+1);
    }
}

void solve() {
    ans = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x;
            cin >> x;

            a[j].emplace_back(x);
        }
    }

    sort(a+1, a+m+1, cmp);

    for(int i = 1; i <= m; i++) {
        for(int x: a[i]) {
            cerr << x << " ";
        }
        cerr << endl;
    }

    f(1);

    cout << ans << endl;

    for(int j = 1; j <= m; j++) a[j].clear();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
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
