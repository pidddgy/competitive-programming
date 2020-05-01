// https://codeforces.com/contest/150/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

vector<int> fac;

void f(int n) {
    if(n == 1) return;

    int x = n;
    for(int i = 2; i <= min((int)sqrt(n)+5, n); i++) {
        if(n%i == 0) {
            x = i;
            break;
        }
    }

    if(x == n) {
        fac.emplace_back(n);
        return;
    } else {
        fac.emplace_back(x);
        f(n/x);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    f(q);

    if(q == 1 or fac.size() == 1) {
        cout << 1 << endl << 0 << endl;
        return 0;
    }

    if(fac.size() == 2) {
        cout << 2 << endl;
        return 0;
    }

    int prod = 1;
    for(int x: fac) {
        prod *= x;
        cerr << x << " ";
    }
    cerr << endl;

    watch(prod)

    cout << 1 << endl;
    cout << (fac[0]*fac[1])  << endl;

}