// https://codeforces.com/contest/567/problem/D

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

int n, k, a;

int f(int x) {
    return (x+1)/(a+1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> a;

    set<int> S;
    S.emplace(0);
    S.emplace(n+1);

    int m;
    cin >> m;

    // watch(m)

    int have = f(n);
    watch(have)
    for(int i = 1; i <= m; i++) {
        watch(i)
        int x;
        cin >> x;

        auto ptr = S.upper_bound(x);
        ptr--;
        int l = (*(ptr));

        int r = (*(S.upper_bound(x)));

        cerr << "inserting " << x << " is in between " << l << " " << r << endl;

        int len = r-l-1;
        have -= f(len);

        cerr << "subtracting " << f(len) << endl;

        int lenl = x-l-1;
        have += f(lenl);

        cerr << "adding " << f(lenl) << endl;

        int lenr = r-x-1;
        have += f(lenr);

        cerr << "adding " << f(lenr) << endl;
 
        cerr << "have is now " << have << endl;


        if(have < k) {
            watch(have)
            cout << i << endl;
            return 0;
        }

        cerr << "emplacing " << x << endl;
        S.emplace(x);

        cerr << endl;
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
