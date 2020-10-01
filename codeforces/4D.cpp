// https://codeforces.com/problemset/problem/4/D

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


struct envel {
    int wid, hei, ind;

    envel(int widd = 0, int heii = 0, int indd = 0) {
        wid = widd;
        hei = heii;
        ind = indd;
    }
};

struct Compare {
    bool operator()(envel &l, envel &r) {
        // return (l.wid < r.wid) and (l.hei < r.hei);
        return pii(l.wid, l.hei) < pii(r.wid, r.hei);
    }
};

const int maxn = 5005;

int pre[maxn], dp[maxn];
envel a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, w, h;
    cin >> n >> w >> h;

    for(int i = 1; i <= n; i++) {
        pre[i] = -1;
        dp[i] = INT_MIN;
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i].wid >> a[i].hei;
        a[i].ind = i;
    }

    sort(a+1, a+n+1, Compare());

    for(int i = 1; i <= n; i++) {
        if((w < a[i].wid) and (h < a[i].hei)) {
            dp[i] = 1;
            pre[i] = i;
        }

        for(int j = 1; j < i; j++) {
            if((a[j].wid < a[i].wid) and (a[j].hei < a[i].hei)) {
                if((dp[j]+1 > dp[i]) and pre[j] != -1) {
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
        }
    }

    if(*max_element(dp+1, dp+n+1) <= 0) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        if(dp[i] == *max_element(dp+1, dp+n+1)) {
            int cur = i;

            cout << dp[i] << endl;
            vector<int> ans;
            while(pre[cur] != cur) {
                // cout << a[cur].ind << " ";
                ans.emplace_back(a[cur].ind);
                cur = pre[cur];
            }
            // cout << a[cur].ind;
            ans.emplace_back(a[cur].ind);

            reverse(all(ans));

            for(int x: ans) cout << x << " ";
            cout << endl;
            // return 0;
            break;
        }
    }
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