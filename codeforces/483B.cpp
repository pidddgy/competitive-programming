// https://codeforces.com/contest/483/problem/B

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
    cin.tie(0);

    int cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;

    int z = x*y;
    int l = 1, r = 2e14;
    int lgood = -1;
    
    while(l <= r) {
        int n= (l+r)/2;

        // only givable to a
        int a =  (n/y - n/z);

        // only givable to b
        int b = (n/x - n/z);

        // can give to both
        int c = n - n/x - n/y + n/z;

        cerr << n << endl;
        cerr << a << " " << b << " " << c << endl;

        if(max(0LL, cnt1-a) + max(0LL, cnt2-b) <= c) {
            lgood = n;
            r = n-1;
        } else {
            l = n+1;
        }
    }

    cout << lgood << endl;
}

/*

how many number are only givable to a, b, both

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
