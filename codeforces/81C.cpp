// https://codeforces.com/contest/81/problem/C

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

void solve() {
    
}

const int maxn = 100500;

int n, a, b;
int ans[maxn];
int used[4];
deque<int> dq[7];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;

    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;

        dq[t].emplace_back(i);
    }

    if(a == b) {
        for(int i = 1; i <= n/2; i++) {
            cout << 1 << " ";
        }

        for(int i = 1; i <= n/2; i++) {
            cout << 2 << " ";
        }

        cout << endl;
        exit(0);
    }

    for(int i = 1; i <= 5; i++) {
        sort(all(dq[i]));
    }

    for(int _ = 1; _ <= n; _++) {
        int use;

        // give to the one where it has the most impact
        if((a < b) and (used[1] < a)) {
            use = 1;
        } else if(used[2] < b) {
            use = 2;
        } else {
            assert(used[1] < a);
            use = 1;
        }

        int ind = -1;
        for(int i = 5; i >= 1; i--) {
            if(sz(dq[i])) {
                if(use == 1) {
                    ind = dq[i].front();
                    dq[i].pop_front();
                } else {
                    ind = dq[i].back();
                    dq[i].pop_back();
                }
                break;
            }
        }
        assert(ind != -1);

        ans[ind] = use;
        used[use]++;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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
