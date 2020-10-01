// https://codeforces.com/problemset/problem/180/E

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

const int maxn = 200500;
const int maxm = 100500;

int n, m, k;
int a[maxn];
// indexes of each color
vector<int> inds[maxm];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        inds[a[i]].emplace_back(i);
    }

    int ans = 0;
    // two pointer on each color
    for(int c = 1; c <= m; c++) {
        cerr << "on color " << c << endl;
        for(int x: inds[c]) {
            cerr << x << " ";
        }
        cerr << endl;

        int l = 0, r = 0;

        int cost = 0;
        while(l < sz(inds[c])) {
            while(r+1 < sz(inds[c])) {
                if(cost + inds[c][r+1]-inds[c][r]-1 <= k) {
                    cost += inds[c][r+1]-inds[c][r]-1;
                    r++;
                } else break;
            }

            cerr << "l is " << inds[c][l] << " and we can go up to " << inds[c][r] << endl;
            watch(cost)
            ans = max(ans, inds[c][r] - inds[c][l] + 1 - cost);
            if(l+1 < sz(inds[c])) {
                cost -= inds[c][l+1]-inds[c][l]-1;
            }
            l++;
        }
    }

    cout << ans << endl;
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
