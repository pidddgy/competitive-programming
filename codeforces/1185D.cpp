// https://codeforces.com/problemset/problem/1185/D

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

pii a[maxn];
int pre[maxn], suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
        pre[i] = suf[i] = LLONG_MIN;
    }

    if(n == 2) {
        cout << 1 << endl;
        return 0;
    }

    sort(a+1, a+n+1);

    for(int i = 2; i <= n; i++) {
        if(a[i].fi-a[i-1].fi != a[2].fi-a[1].fi) break;

        pre[i] = a[2].fi-a[1].fi;
    }

    for(int i = n-1; i >= 1; i--) {
        if(a[i+1].fi-a[i].fi != a[n].fi-a[n-1].fi) break;

        suf[i] = a[i+1].fi-a[i].fi;
    }

    if(pre[n-1] != LLONG_MIN) {
        cout << a[n].se << endl;
        return 0;
    }

    if(suf[2] != LLONG_MIN) {
        cout << a[1].se << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        if(pre[i] == LLONG_MIN) cerr << "I ";
        else cerr << pre[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        if(suf[i] == LLONG_MIN) cerr << "I ";
        else cerr << suf[i] << " ";
    }
    cerr << endl;

    for(int i = 2; i <= n-1; i++) {
        if((pre[i-1] == suf[i+1] or i == 2 or i == n-1) and max(pre[i-1], suf[i+1]) == a[i+1].fi-a[i-1].fi) {
            cout << a[i].se << endl;
            return 0;
        }
    }



    cout << -1 << endl;
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
