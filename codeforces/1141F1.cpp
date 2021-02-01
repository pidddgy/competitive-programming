// https://codeforces.com/contest/1141/problem/F1

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

const int maxn = 55;

int n;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<pii> ans;
    // for(int i = -5e6; i <= 5e6; i++) {
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = i; j <= n; j++) {
            sum += a[j];

            map<int, int> mp;
            mp[0] = 0;
            int cum = 0;

            vector<pii> loc;

            watch(sum)
            for(int k = 1; k <= n; k++) {
                cum += a[k];

                cerr << k << " " << cum << endl;

                if(mp.count(cum-sum)) {
                    cerr << "made" << endl;
                    loc.emplace_back(mp[cum-sum]+1, k);
                    mp.clear();
                    cum = 0;
                }

                mp[cum] = k;
            }

            // best = max(best, {loc, i});
            cerr << "ans is " << sz(loc) << endl;
            if(sz(loc) > sz(ans)) ans = loc;
        }
    }

    cout << sz(ans) << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}

/*

can greedy, exchange argument

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
