// https://codeforces.com/contest/1408/problem/C

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

const int maxn = 100500;

int n, l;
ld a[maxn];

ld timea(ld x) {
    ld res = 0;
    int speed = 1;

    for(int i = 1; i <= n+1; i++) {
        ld sp = speed;
        if(a[i] < x) {
            // cerr << "travelling from " << a[i-1] << " to " << a[i] << ", sp = " << sp << endl;
            ld dis = (a[i]-a[i-1]);
            res += dis/sp;
            speed++;
        } else {
            // cerr << "travelling from " << a[i-1] << " to " << x << ", sp = " << sp << endl;
            ld dis = (x-a[i-1]);
            res += dis/sp;
            break;
        }
    }

    return res;
}

ld timeb(ld x) {
    ld res = 0;
    int speed = 1;

    for(int i = n; i >= 0; i--) {
        ld sp = speed;
        if(a[i] > x) {
            // cerr << "travelling from " << a[i+1] << " to " << a[i] << " with speed " << sp << endl;
            ld dis = (a[i+1]-a[i]);
            res += dis/sp;
            speed++;
        } else {
            // cerr << "travelling from " << a[i+1] << " to " << x << " with speed " << sp << endl;
            ld dis = (a[i+1]-x);
            res += dis/sp;
            break;
        }
    }

    return res;
}

void solve() {
    cin >> n >> l;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n+1] = l;

    // ld test = timeb(10);
    // watch(test)
    ld lb = 0, rb = l;
    for(int i = 1; i <= 100; i++) {
        ld mid = (lb+rb)/(ld)(2.0);

        cerr << "trying " << mid << endl;
        // too big if the left reaches first
        if(timea(mid) < timeb(mid)) {
            cerr << "too far to left" << endl;
            lb = mid;
        } else if(timea(mid) > timeb(mid)) {
            cerr << "too far to right" << endl;
            rb = mid;
        } else break;
    }
    ld pt = (lb+rb)/(ld)(2.0);
    watch(pt)
    cout << timea(pt) << endl;
    watch(timeb(pt))

    for(int i = 1; i <= n+1; i++) {
        a[i] = 0;
    }
    cerr << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

get time from each car to any point

binary search on distance

if c1 < c2 too small
if c2 > c1 too big

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
