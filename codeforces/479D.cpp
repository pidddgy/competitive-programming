// https://codeforces.com/contest/479/problem/D

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
int n, l, x, y;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> x >> y;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> have;
    // int xmabs = -1, xpy = -1;
    vector<int> xmabs;
    bool havex = false, havey = false;
    int xpy = -1;
    for(int i = 1; i <= n; i++) {
        have[a[i]] = true;

        if(have[a[i]-x]) havex = true;
        if(have[a[i]-y]) havey = true;

        if(have[a[i]-abs(x-y)]) {
            xmabs.emplace_back(i);
        }

        if(have[a[i]-(x+y)]) {
            xpy = i;
        }
    }

    if(havex and havey) {
        cout << 0 << endl;
        return 0;
    } else if(havex) {
        cout << 1 << endl;
        cout << y << endl;
        return 0;
    } else if(havey) {
        cerr << "a" << endl;
        cout << 1 << endl;
        cout << x << endl;
        return 0;
    }
    
    for(int ind: xmabs) {
        // put it on left side of pair
        if(a[ind]-max(x, y) >= 1) {
            cout << 1 << endl;
            cout << a[ind]-max(x, y) << endl;
            return 0;
        }

        if(a[ind]-abs(x-y) + max(x, y) <= l) {
            cout << 1 << endl;
            cout << a[ind]-abs(x-y) + max(x, y) << endl;
            return 0;
        }
    }

    if(xpy != -1) {
        cout << 1 << endl;
        cout << a[xpy] - x << endl;
        return 0;
    }


    cout << 2 << endl;
    cout << x << " " << y << endl;
}

/*

implicit bound, <= 2

if both already exist then put 0
if one exists or there is a gap of length x+y then put 1
rather than dividing we can also put a mark to the left/right of a pair if the gap between the pair is abs(x-y)

else just put 2

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
