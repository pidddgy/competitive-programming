// https://codeforces.com/contest/1010/problem/C

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

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

const int maxn = 100500;

int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int g = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= k;

        g = gcd(a[i], g);

    }
    set<int> ans;

    int s = 0;
    for(int i = 0; i < k; i++) {
        s += g;
        ans.emplace(s%k);
    }

    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;

    
}

/*

last digit = residue mod k

bezouts identity, ax + by + cz = res exists if res is divisible by gcd(a, b, c)

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?