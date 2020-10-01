// https://codeforces.com/contest/1393/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

// struct hugs {
//     int ind, cnt, val;
//     hugs(int indd, int cntt, int vall) {
//         ind = indd;
//         cnt = cntt;
//         val = vall;
//     }
// };

// // remember that pq sort puts max first
// struct Compare {
//     bool operator()(hugs &l, hugs &r) {
//         return l.ind > r.ind;
//     }
// };

void solve() {
    int n;
    cin >> n;

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        cnt[a]++;
    }   

    int l = 0;
    int r = 2e5;
    int lgood = -1;
    while(l <= r) {
        int m = (l+r)/2;
        bool ok = true;
        
        // .fi = index, .se = remaining
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for(pii x: cnt) {
            pq.push(pii(1, x.se));
        }

        for(int i = 1; i <= n; i++) {
            pii cur = pq.top();
            pq.pop();

            if(cur.fi > i) {
                ok = false;
                break;
            }

            cur.fi += m+1;
            cur.se--;
            if(cur.se > 0) {
                pq.push(cur);
            }
        }



        if(ok) {
            lgood = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    assert(lgood != -1);
    cout << lgood << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // priority_queue<hugs, vector<hugs>, Compare> test;

    // test.push(hugs(1, 2, 3));
    // test.push(hugs(120, 2, 3));
    // test.push(hugs(3, 2, 3));
    // test.push(hugs(200, 2, 3));

    // while(sz(test)) {
    //     cout << (test.top()).ind << " ";
    //     test.pop();
    // }
    // cout << endl;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }   
}

/*
push them all in a queue, saying "you can eat this patty if the current index is >= x"

binary search for max possible distance
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
