// https://codeforces.com/contest/260/problem/C

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

int a[maxn];
int tot = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    int mi = LLONG_MAX, miind = -1;
    for(int i = 1; i <= n; i++) {
        if(a[x] < mi) {
            mi = a[x];
            miind = x;
        }

        x--;
        if(x == 0) x = n;
    }

    // x is now back to original
    bool f = false;
    for(int i = 1; i <= n; i++) {
        a[x] -= mi;
        if(x == miind) f = true;

        if(!f) {
            a[x]--;
        }
        x--;
        if(x == 0) x = n;
    }

    for(int i = 1; i <= n; i++) {
        tot -= a[i];
    }

    a[miind] += tot;

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*

constructive, ad hoc

count things we keep and subtract rather than counting things we remove (could be replaced but makes life easier)

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
