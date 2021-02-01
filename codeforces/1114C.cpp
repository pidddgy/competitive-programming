// https://codeforces.com/problemset/problem/1114/C 

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

map<int, int> fac(int num) {
    map<int, int> res;
    int cpy = num;
    for(int i = 2; i*i <= cpy; i++) {
        while(num%i == 0) {
            res[i]++;
            num /= i;
        }
    }

    if(num != 1)
    res[num]++;

    return res;
}

map<int, int> bfac;

map<int, int> facf(int num) {
    map<int, int> res;

    for(pii x: bfac) {
        int cpy = num;
        while(cpy > 0) {
            res[x.fi] += cpy/x.fi;
            cpy /= x.fi;
            watch(cpy)
            watch(x.fi)
        }
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, b;
    cin >> n >> b;

    bfac = fac(b);

    auto m = facf(n);

    for(pii x: bfac) {
        cerr << x.fi << " " << x.se << endl;
    }
    int ans = 1e18;
    for(pii x: bfac) {
        ans = min(ans, m[x.fi]/x.se);
    }

    cout << ans << endl;
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
