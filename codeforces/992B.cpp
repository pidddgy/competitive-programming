// https://codeforces.com/contest/992/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }
int l, r, x, y;

bool ok(int n) {
    return ((l <= n) and (n <= r));
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> r >> x >> y;

    set<int> div;
    for(int i = 1; i*i <= y; i++) {
        if(y%i == 0) {
            for(int _: set<int>({i, y/i})) {
                div.emplace(_);
            }
        }
    }

    int ans = 0;
    for(int i: div) {
        for(int j: div) {
            if(ok(i) and ok(j) and gcd(i, j) == x and lcm(i, j) == y) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}