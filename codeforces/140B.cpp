// https://codeforces.com/contest/140/problem/B

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

const int maxn = 308;

// a[i][j] = how much does friend i like card j (lower = better)
int a[maxn][maxn];

int ans[maxn];

int n;

struct Compare {
    bool operator()(int l, int r) {
        return a[n+1][l] < a[n+1][r];
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        ans[i] = -1;
    }

    cin >> n;

    for(int i = 1; i <= n+1; i++) {
        for(int j = 1; j <= n; j++) {
            int x;
            cin >> x;

            a[i][x] = j;
            // cin >> a[i][j];
        }
    }

    set<int, Compare> cards;

    for(int i = 1; i <= n; i++) {
        cards.emplace(i);

        for(int j = 1; j <= n; j++) {
            for(int x: cards) {
                if(x != j) {
                    if((ans[j] == -1) or (a[j][x] < a[j][ans[j]])) {
                        ans[j] = i;
                    }
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}   


/*

for each received
    for each friend
        min 

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
