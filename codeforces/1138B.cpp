// https://codeforces.com/contest/1138/problem/B

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    s = "."+s;
    t = "."+t;

    vector<int> a, b, c, d;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0' and t[i] == '0') {
            a.emplace_back(i);
        } else if(s[i] == '0' and t[i] == '1') {
            b.emplace_back(i);
        } else if(s[i] == '1' and t[i] == '0') {
            c.emplace_back(i);
        } else if(s[i] == '1' and t[i] == '1') {
            d.emplace_back(i);
        }
    }

    for(int tc = 0; tc <= c.size(); tc++) {
        for(int td = 0; td <= d.size(); td++) {
            int tb = (b.size()+d.size()) - (tc + 2*td);
            int ta = (((n/2) - tc) - td) - tb;

            if(ta >= 0 and ta <= a.size() and 
                tb >= 0 and tb <= b.size()) {
                    for(int i = 0; i < ta; i++) {
                        cout << a[i] << " ";
                    }

                    for(int i = 0; i < tb; i++) {
                        cout << b[i] << " ";
                    }

                    for(int i = 0; i < tc; i++) {
                        cout << c[i] << " ";
                    }

                    for(int i = 0; i < td; i++) {
                        cout << d[i] << " ";
                    }

                    cout << endl;
                    return 0;
                } 
        }
    }

    cout << -1 << endl;
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