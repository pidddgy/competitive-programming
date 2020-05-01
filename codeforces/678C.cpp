// https://codeforces.com/contest/678/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    int ac = 0;
    int bc = 0;

    ac += n/a;
    bc += n/b;

    // watch(ac)
    // watch(bc)

    // watch(lcm(a, b))

    if(p > q) {
        bc -= n/(lcm(a, b));
    } else if (q > p) {
        ac -= n/(lcm(a, b));
    } else if(a > b) {
        ac -= n/(lcm(a, b));
    } else if(b > a) {
        bc -= n/(lcm(a, b));
    } else if(p > q) {
        bc -= n/(lcm(a, b));
    } else {
        ac -= n/(lcm(a, b));
    }

    // watch(ac)
    // watch(bc)

    cout << ac*p + bc*q << endl;
}