// https://codeforces.com/contest/998/problem/A

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

const int maxn = 15;

int a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if(n == 1 or (n == 2 and a[1] == a[2])) {
        cout << -1 << endl;
        return 0;
    }

    int mi = a[1];
    int miind = 1;

    for(int i = 2; i <= n; i++) {
        if(a[i] < mi) {
            mi = a[i];
            miind = i;
        } 
    }
    cout << 1 << endl;
    cout << miind << endl;
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
