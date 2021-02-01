// https://codeforces.com/contest/1445/problem/C

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

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

int spow(int a, int exp) {
    int res = 1;
    for(int i = 1; i <= exp; i++) {
        res *= a;
    }
    return res;
}
void solve() {
    int p, q;
    cin >> p >> q;

    if(p % q) {
        cout << p << endl;
        return;
    }

    const int pcpy = p;
    const int qcpy = q;
    int ma = 0;

    for(int i = 2; i*i <= q; i++) {
        int cnt = 0;
        while(q%i == 0) {
            cnt++;
            q /= i;
        }

        if(cnt != 0) {
            cerr << i << " appears " << cnt << endl;
            int pcnt = 0;
            while(p%i == 0)  {
                pcnt++;
                p /= i;
            }

            watch(pcnt);

            int take = max(0LL, pcnt-cnt+1);

            watch(take)

            watch(spow(i, take))

            if(pcnt >= take) {
                watch(pcpy/(max(1LL, spow(i, take))))
                ma = max(ma, pcpy/(max(1LL, spow(i, take))));
            }
        }
    }

    if(q != 1) {
        int pcnt = 0;
        while(p%q == 0)  {
            pcnt++;
            p /= q;
        }

        int take = max(0LL, pcnt);

        if(pcnt >= take)
        ma = max(ma, pcpy/(max(1LL, spow(q, take))));
    }

    cout << ma << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*
x is a factor of p
q is not a factor of x

remove some factors from p so that q is not a subset

brute force over sqrt q
pick a factor to reduce

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
