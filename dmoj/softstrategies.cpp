// https://dmoj.ca/problem/oly20practice106

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

int divisors(int n) {
    int ret = 0;
    for(int i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            ret += sz(set<int>({i, n/i}));
        }
    }
    return ret;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int squares = 0;
    for(int i = 1; i <= 3e5; i++) {
        if((i*i <= n) and (i*i)&1) squares++;   
    }
    // watch(squares)
    cout << ((n+1)/2)-squares << endl;
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
