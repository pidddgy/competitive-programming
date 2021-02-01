// https://dmoj.ca/problem/oly20practice117

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

int f(int l, int r, int x) {
    return (r/x) - ((l-1)/x);
}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, a, b;
    cin >> x >> y >> a >> b;

    watch(f(x, y, a))
    watch(f(x, y, b))
    cout << f(x, y, a) + f(x, y, b) -  f(x, y, lcm(a, b)) << endl;

}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
