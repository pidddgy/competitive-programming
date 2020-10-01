// https://codeforces.com/contest/402/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxnm = 5500;

int a[maxnm], b[maxnm];
set<int> bS;

map<int, int> pfac(int n) {
    map<int, int> res;
    for(int i = 2; i*i <= n; i++) {
        while(n%i == 0) {
            res[i]++;
            n /= i;
        }
    }

    if(n > 1) {
        res[n]++;
    }

    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        bS.emplace(b[i]);
    }

    for(int i = n; i >= 1; i--) {
        int g = a[1];
        for(int j = 2; j <= i; j++) {
            g = __gcd(g, a[j]);
        }
        int cpy = g;

        map<int, int> fac = pfac(g);

        int bad = 0, good = 0;
        for(pii x: fac) {
            if(bS.count(x.fi)) {
                bad += x.se;
            } else {
                good += x.se;
            }
        }

        if(bad >= good) {
            for(int j = 1; j <= i; j++) {
                a[j] /= cpy;
            }
        }
    }

    int bad = 0, good = 0;
    for(int i = 1; i <= n; i++) {
        map<int, int> fac = pfac(a[i]);

        for(pii x: fac) {
            if(bS.count(x.fi)) {
                bad += x.se;
            } else {
                good += x.se;
            }
        }
    }

    cout << (good-bad) << endl;
}
