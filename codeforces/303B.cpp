// https://codeforces.com/contest/303/problem/B

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

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, X, Y, A, B;
    cin >> N >> M >> X >> Y >> A >> B;

    int g = __gcd(A, B);
    A /= g;
    B /= g;

    // cerr << a << " " << b << endl;

    int len = 0, wid = 0;

    // a = length
    // b = width

    int l = 1;
    int r = 2e9;

    while(l <= r) {
        int mid = (l+r)/2;

        cerr << "trying " << mid << endl;

        int cl = mid*A;
        int cw = mid*B;

        cerr << cl << " " << cw << endl;
        cerr << N << " " << M << endl;

        if((cl <= N) and (cw <= M)) {
            cerr << "good" << endl;
            len = cl;
            wid = cw;

            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cerr << len << " " << wid << endl;

    int ax1 = 0, ay1 = 0, ax2 = len, ay2 = wid;

    for(int i = 30; i >= 0; i--) {
        int adj = (1LL << i);

        ld nx1 = ax1+adj;
        ld nx2 = ax2+adj;

        if(((nx1+nx2) / 2.0 <= (ld)X) and (nx2 <= N)) {
            ax1 += adj;
            ax2 += adj;
        }
    }

    for(int i = 30; i >= 0; i--) {
        int adj = (1LL << i);

        ld ny1 = ay1 + adj;
        ld ny2 = ay2 + adj;

        if(((ny1+ny2) / 2.0 <= (ld)Y) and (ny2 <= M)) {
            ay1 += adj;
            ay2 += adj;
        }
    }

    cout << ax1 << " " << ay1 << " " << ax2 << " " << ay2 << endl;

}

/*
use gcd to reduce a and b into coprime

binary search for biggest possible rectangle

loop over big powers of 2 to adjust
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
