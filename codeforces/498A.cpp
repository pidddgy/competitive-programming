// https://codeforces.com/contest/498/problem/A

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

bool in(ld num, ld b1, ld b2) {
    return (min(b1, b2) <= num and num <= max(b1, b2));
}

const int maxn = 350;
ld x[5], y[5];
int n;
ld a[maxn], b[maxn], c[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    for(int i = 1; i <= 2; i++) {
        cin >> x[i] >> y[i];
    }

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            // horizontal
            ld ypos = (-c[i])/b[i];

            if(in(ypos, y[1], y[2])) ans++;
        } else if(b[i] == 0) {
            // vertical
            ld xpos = (-c[i])/a[i];

            if(in(xpos, x[1], x[2])) ans++;

        } else {
            // A/B/C_1
            int A1 = (y[1]-y[2]), B1 = (x[2]-x[1]);
            int C1 = -(A1*x[1] + B1*y[1]);

            int A2 = a[i], B2 = b[i], C2 = c[i];

            // parallel
            if(A1*B2 == A2*B1) {
                continue;
            }

            ld xc, yc;

            xc = (ld)(B1*C2 - B2*C1) / (ld)(B2*A1 - B1*A2);
            yc = (ld)(A1*C2 - A2*C1) / (ld)(A2*B1 - A1*B2);

            // watch(xc)
            // watch(yc)

            if(in(xc, x[1], x[2]) and in(yc, y[1], y[2])) ans++;
        }
    }

    cout << ans << endl;
}

/*

x + y - 3 = 0

1 1
3 3
1
1 -1 -2

B_2*A_1*x - B_1*A_2*x + B_2*C_1 − B_1*C_2 = 0
B_2*A_1*x - B_1*A_2*x = -(B_2*C_1 −B_1*C_2) = 0
B_2*A_1*x - B_1*A_2*x = B_2*C_1 + B_1*C_2 = 0

x(B_2*A_1 - B_1*A_2) = B_2*C_1 + B_1*C_2 = 0


b_2*a_1*x - b_1*a_2*x + b_2*c_1 - b_1*c_2 = 0
b_2*a_1*x - b_1*a_2*x = b_1*c_2 - b_2*c_1

x(b_2*a_1-b_1*a_2) = b_1*c_2-b_2*c_1
x = (b_1*c_2-b_2*c_1) / (b_2*a_1-b_1*a_2)



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
