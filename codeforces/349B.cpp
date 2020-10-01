// https://codeforces.com/problemset/problem/349/B

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

int a[15];
int ans[(int)1e6+5];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int v;
    cin >> v;

    int mi = 1;
    for(int i = 1; i <= 9; i++) {
        cin >> a[i];
        if(a[i] <= a[mi]) {
            mi = i;
        }
    }

    int digits = v/(a[mi]);
    
    if(digits == 0) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= digits; i++) {
        ans[i] = mi;
        v -= a[mi];
    }

    for(int i = 1; i <= digits; i++) {
        cerr << ans[i];
    }
    cerr << endl;

    for(int i = 1; i <= digits; i++) {
        for(int j = 9; j > mi; j--) {
            if(a[j] <= v+a[ans[i]]) {
                v -= a[j];
                v += a[ans[i]];
                ans[i] = j;
                break;
            }
        }

        cout << ans[i];
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
