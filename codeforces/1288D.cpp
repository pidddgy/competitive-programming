// https://codeforces.com/problemset/problem/1288/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int maxn = 300050;
const int maxm = 10;

int a[maxn][maxm];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int l = 0;
    int r = 1e9;
    pii ans = pii(-1, -1);

    while(l <= r) {
        int mid = (l+r) / 2;
        cerr << "trying " << mid << endl;
        set<pii> masks;
        set<int> dup;
        for(int i = 1; i <= n; i++) {
            int mask = 0;
            for(int j = 1; j <= m; j++) {
                if(a[i][j] >= mid) {
                    mask |= (1LL << (j-1));
                }
            }
            cerr << bitset<8>(mask) << endl;

            if(!dup.count(mask)) {
                masks.emplace(pii(mask, i));
                dup.emplace(mask);
            }
        }

        bool good = false;
        for(pii x: masks) {
            for(pii y: masks) {
                if(good) break;

                if((x.fi | y.fi) == (1 << (m))-1) {
                    good = true;
                    ans.fi = x.se;
                    ans.se = y.se;
                }
            }
        }

        if(good) {
            cerr << "good" << endl;
            watch(ans.fi)
            watch(ans.se)
            l = mid+1;
        } else {
            cerr << "not good" << endl;
            r = mid-1;
        }
        cerr << endl;
    }

    cerr << bitset<8>((1<<m)-1) << endl;

    cout << ans.fi << " " << ans.se << endl;
}

/*
6 5
5 0 3 1 2
1 8 9 1 3
1 2 3 4 5
9 1 0 3 7
2 3 0 6 3
6 4 1 7 0


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?