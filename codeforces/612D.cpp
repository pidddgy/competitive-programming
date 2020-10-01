// https://codeforces.com/contest/612/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxv = (int)4e6+50;
int n, k;
vector<pii> ans;
vector<int> cmp;
int ma = 0;
// map<int, int> add, sub;

int add[maxv], sub[maxv];
int l[maxv], r[maxv];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;    

    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        cmp.emplace_back(l[i]);
        cmp.emplace_back(r[i]);
    }

    sort(all(cmp));
    cmp.erase(unique(all(cmp)), cmp.end());

    for(int i = 1; i <= n; i++) {
        // l[i] = 
        l[i] = lower_bound(all(cmp), l[i]) - cmp.begin();
        r[i] = lower_bound(all(cmp), r[i]) - cmp.begin();
    }

    for(int i = 1; i <= n; i++) {
        ma = max({ma, l[i], r[i]});

        add[l[i]]++;
        sub[r[i]]++;
    }
    
    int cur = 0;
    int last = INT_MIN;

    vector<pii> ans;
    for(int x = 0; x <= 4e6; x++) {
        cur += add[x];

        if(cur < k) {
            if(last != INT_MIN) {
                ans.emplace_back(last, x);
                last = INT_MIN;
            } 
        } else {
            if(last == INT_MIN) {
                last = x;
            }
        }

        cur -= sub[x];

        if(cur < k) {
            if(last != INT_MIN) {
                ans.emplace_back(last, x);
                last = INT_MIN;
            } 
        } else {
            if(last == INT_MIN) {
                last = x;
            }
        }
    }

    if(cur >= k) {
        ans.emplace_back(last, ma);
    }

    cout << sz(ans) << endl;
    for(pii x: ans) {
        cout << cmp[x.fi] << " " << cmp[x.se] << endl;
    }
}

/*

some line sweep kinda thing

push events, iterate over all the events and keep track of how many lines are covering this point 

keep track of the last point with >= k

if we hit a point with < k covers and there is a last point, then push a new segment and reset the last point

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?