// https://codeforces.com/contest/750/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr cout
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second
#define int long long


const int maxn = 200500;

int c[maxn], d[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
    }

    int gthan = INT_MIN, lthan = INT_MAX;

    int cur = 0;
    for(int i = 1; i <= n; i++) {
        watch(cur)
        watch(d[i])
        if(d[i] == 1) {
            gthan = max(gthan, 1900-cur);
            cerr << "greater than " << 1900-cur << endl;
        } else {
            lthan = min(lthan, 1899-cur);
            cerr << "less than " << 1899-cur << endl;
        }

        cur += c[i];
        cerr << endl;
    }

    cerr << "must be >= " << gthan << endl;
    cerr << "must be <= " << lthan << endl;
    if(lthan == INT_MAX) {
        cout << "Infinity" << endl;
    } else if(gthan <= lthan) {
        cout << lthan+cur << endl;
    } else {
        cout << "Impossible" << endl;
    }
}