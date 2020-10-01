// https://codeforces.com/contest/1154/problem/E

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
#define all(x) (x).begin(), (x).end()

const int maxn = 200500;

pii a[maxn];
int ans[maxn];
set<int> S;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        S.emplace(i);

        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(a+1, a+n+1, greater<pii>());
    int turn = 1;
    for(int i = 1; i <= n; i++) {
        int ind = a[i].se;
        if(!S.count(ind)) continue;

        set<int> rem;
        rem.emplace(ind);

        auto it = S.lower_bound(ind);
        for(int j = 1; j <= k; j++) {
            cerr << "it is currently at " << (*it) << endl;
            it++;
            cerr << "now currently at " << (*it) << endl;
            if(it == S.end()) break;

            rem.emplace(*it);
        }

        it = S.lower_bound(ind);
        for(int j = 1; j <= k; j++) {
            if(it == S.begin()) break;
            it--;
            rem.emplace(*it);
        }

        watch(turn)
        for(int x: rem) {
            if(turn&1) {
                cerr << "setting " << x << " to 1" << endl;
                ans[x] = 1;
            } else {
                cerr << "setting " << x << " to 2" << endl;
                ans[x] = 2;
            }
            S.erase(x);
        }

        cerr << endl;
        turn ^= 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << endl;
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
