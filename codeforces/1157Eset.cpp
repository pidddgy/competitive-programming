// https://codeforces.com/contest/1157/problem/E

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

int a[maxn], ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    multiset<int> S;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        S.emplace(x);
    }

    for(int i = 1; i <= n; i++) {
        auto it = S.lower_bound(n-a[i]);
        if(it == S.end()) it = S.begin();

        int use = *it;

        ans[i] = (a[i]+use)%n;
        S.erase(it);
    }   

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
