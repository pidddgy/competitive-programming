// https://codeforces.com/contest/1151/problem/C

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

const int MOD = (int)1e9+7;

int mod(int x) {
    return (x+MOD)%MOD;
}
// get sum of first l to r numbers with parity = par
int f(int l, int r, int par) {
    assert(par == 0 or par == 1);

    l = mod(l);
    r = mod(r);

    int a = mod(mod(r * (r+(par^1))));
    int b = mod(mod( ((l-1) * ((l-1)+(par^1))) ));

    return mod(mod(a-b));
}

int query(int x) {
    int len = 1;
    int cur = 1;
    int parity = 1;
    int even = 1, odd = 1;

    int ans = 0;
    while(cur <= x) {
        int upto = min(cur+len-1, x);
        int take = upto-cur+1;

        if(parity == 1) {
            ans += mod(f(odd, odd+take-1, 1));
        } else {
            ans += mod(f(even, even+take-1, 0));
        }

        ans = mod(ans);

        if(parity == 1) {
            odd += take;
        } else {
            even += take;
        }

        parity ^= 1;
        cur = upto+1;
        len *= 2;
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, r;
    cin >> l >> r;

    int ree = query(r);
    int ree2 = query(l-1);

    cout << mod(ree-ree2) << endl;
}

/*

x'th even number is 2*x
sum of first x even numbers is x(2*x+2) / 2 = x(x+1)
sum of first x odd numbers is x*x

use inclusion exclusion

it grows really fast so just brute force?

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
