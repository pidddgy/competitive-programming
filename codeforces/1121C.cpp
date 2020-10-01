// https://codeforces.com/contest/1121/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define ld long double
#define pii pair<int, int>
#define pipii pair<int, pii>
#define fi first
#define se second

pipii test[105];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    deque<pii> a;
    for(int i = 1; i <= n; i++) {
        int b;
        cin >> b;

        a.push_back(pii(b, i));
    }

    int ans = 0;
    int done = 0;
    map<int, int> seen;
    for(int iter = 0; iter < 250000; iter++) {

        
        cerr << "on moment " << iter << endl;
        for(int i = 1; i <= k; i++) {
            if(test[i].se.fi == 0 and test[i].se.se == 0) {
                if(a.size()) {
                    cerr << "starting to test " << a.front().fi << endl;
                    test[i] = pipii(a.front().se, pii(a.front().fi, 1));
                    a.pop_front();
                }
            }
        }

        if(iter == 0) continue;

        // int d = int((100.0 * ((ld)done/(ld)n))+0.5);
        int d = round(100.0 * ((ld)done/(ld)n));

        for(int i = 1; i <= k; i++) {
            if(test[i].fi == 0) continue;
            if(test[i].se.se == d and !seen[test[i].fi]) {
                seen[test[i].fi] = true;
                cerr << " ind " << test[i].fi << " " << test[i].se.fi << "," << test[i].se.se << " is interesting" << endl;
                ans++;
            }
        }

        for(int i = 1; i <= k; i++) {
            if(test[i].se.fi == 0) continue;

            cerr << test[i].se.fi << "," << test[i].se.se << endl;
            if(test[i].se.fi == test[i].se.se) {
                done++;
                cerr << "is now done" << ", done is now " << done <<  endl;

                int d = round(100.0 * ((ld)done/(ld)n));
                cerr << "caption is now " << d << endl;
                test[i].se.fi = 0;
                test[i].se.se = 0;

                if(a.size()) {
                    cerr << "starting to test " << a.front().fi << endl;
                    test[i] = pipii(a.front().se, pii(a.front().fi, 0));
                    a.pop_front();
                }
            }
        }

        for(int i = 1; i <= k; i++) {
            if(test[i].se.fi > test[i].se.se) {
                test[i].se.se++;
            }
        }



        cerr << endl;
    }

    cout << ans << endl;
}