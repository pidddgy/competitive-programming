// https://codeforces.com/contest/1395/problem/B

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

bool vis[200][200];
int n, m, sx, sy;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> sx >> sy;

    vector<pii> ans;

    ans.emplace_back(sx, sy);

    // left -> right
    for(int i = 1; i <= m; i++) {
        if(i != sy) {
            ans.emplace_back(sx, i);
        }
    }    

    // if current should start from right
    bool right = true;

    // the one 1 distance away goes from right -> left, next goes left -> right, so on
    for(int i = sx+1; i <= n; i++) {
        if(right) {
            for(int j = m; j >= 1; j--) {
                ans.emplace_back(i, j);
            }
        } else {
           for(int j = 1; j <= m; j++) {
                ans.emplace_back(i, j);
            }
        }

        right ^= 1;
    }


    for(int i = sx-1; i >= 1; i--) {
        if(right) {
            for(int j = m; j >= 1; j--) {
                ans.emplace_back(i, j);
            }
        } else {
           for(int j = 1; j <= m; j++) {
                ans.emplace_back(i, j);
            }
        }
        
        right ^= 1;
    }
    
    
    // assert(ans.size() == (n*m));

    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
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
