// https://codeforces.com/contest/610/problem/C

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

const int maxk = 13;

vector<vector<int>> ans[maxk];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ans[0] = {{1}};

    for(int ind = 1; ind <= 9; ind++) {
        watch(ind)
        int pre = sz(ans[ind-1]);
        watch(pre)
        vector<vector<int>> cur(2*pre, vector<int>(2*pre, 0));

        for(auto x: cur) {
            for(int y: x) {
                cerr << y << " ";
            }
            cerr << endl;
        }

        for(int i = 0; i < pre; i++) {
            for(int j = 0; j < pre; j++) {
                cerr << i << " " << j << endl;
                cur[i][j] = cur[i+pre][j] = cur[i][j+pre] = ans[ind-1][i][j];

                cur[i+pre][j+pre] = ans[ind-1][i][j]^1;
            }
        }

        ans[ind] = cur;
    }

    int n;
    cin >> n;

    for(vector<int> v: ans[n]) {
        for(int x: v) {
            // cout << x << " ";
            if(x == 1) cout << "*";
            else cout << "+";
        }
        cout << endl;
    }
}

/*

number of set bits in xor of any pair should be n/2

idea: how can we use previous states to build on answer?

we need to find a construction where a pair from the top half is 0 and any top and bottom is 0

we we copy 3 times and invert bottom right

we need to fix the pairs with same row position from old
the only case where things have the same are top and bottom right
flipping doesn't actually impact non-identical rows because non-set bits become set and of the thing where the previous state needs to have n/2 for any pair of rows

********
*+*+*+*+
**++**++
*++**++*
****++++
*+*++*++
**++++*+
*++*++++

1 1 1 1 1 1 1 1 
1 0 1 0 1 0 1 0 
1 1 0 0 1 1 0 0 
1 0 0 1 1 0 0 1 
1 1 1 1 0 0 0 0 
1 0 1 0 0 1 0 0 
1 1 0 0 0 0 1 0 
1 0 0 1 0 0 0 0 
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
