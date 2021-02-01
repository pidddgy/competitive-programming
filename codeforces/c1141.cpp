// https://cses.fi/problemset/task/1141

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

const int maxn = 200500;

int n;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    int r = 1;
    set<int> S;
    S.emplace(a[1]);
    for(int l = 1; l <= n; l++) {
        cerr << "on " << l << endl;

        while(r < n and !S.count(a[r+1])) {
            cerr << "emplacing " << r+1 << endl;
            S.emplace(a[r+1]);
            r++;
        }

        cerr << l << " " << r << endl;

        ans = max(ans, r-l+1);
        cerr << "erasing " << l << endl;
        S.erase(a[l]);
    }

    cout << ans << endl;
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
