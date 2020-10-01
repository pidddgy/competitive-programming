// https://codeforces.com/problemset/problem/547/B

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

const int maxn = 200500;

int n;

// l = first left element < a[i], r = first right element < a[i]
int a[maxn], l[maxn], r[maxn], ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        r[i] = n+1;
    }

    stack<int> s;

    for(int i = 1; i <= n; i++) {
        while(sz(s) and a[s.top()] >= a[i]) {
            s.pop();
        }

        if(sz(s)) {
            l[i] = s.top();
        }

        s.push(i);
    }

    while(sz(s)) s.pop();

    for(int i = n; i >= 1; i--) {
        while(sz(s) and a[s.top()] >= a[i]) {
            s.pop();
        }

        if(sz(s)) {
            r[i] = s.top();
        }

        s.push(i);
    }

    for(int i = 1; i <= n; i++) {
        int len = r[i] - l[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }

    for(int i = n; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i+1]);
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
