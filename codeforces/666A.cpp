// https://codeforces.com/problemset/problem/666/A

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

const int MAXN = 10050;

string s;
int n;

// 0 == 2, 1 == 3
bool dp[MAXN][5];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = sz(s);
    s = "."+s;
    for(int i = 1; i <= MAXN; i++) {
        s.push_back('?');
    }

    set<string> ans;
    for(int i = n; i >= 6; i--) {
        // j is how much we add (add 2 to j)
        for(int j = 0; j <= 1; j++) {
            if(i+j+1 <= n) {
                if(i+j+1 == n) {
                    dp[i][j] = true;
                }

                if((i+j+2 <= n) and (s.substr(i+j+2, j+2) != s.substr(i, j+2))) {
                    dp[i][j] |= dp[i+j+2][j];
                }

                if((i+j+2) <= n) {
                    dp[i][j] |= dp[i+j+2][j^1];
                }
            }

            if(dp[i][j]) {
                ans.emplace(s.substr(i, j+2));
            }
        }
    }

    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= 1; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    cout << sz(ans) << endl;
    for(string x: ans) {
        cout << x << endl;
    }
}

/*

"interval" dp kinda

dp[i][j] = if the suffix from i...n can can form some splitting with the first using 2 or 3

realize that if we want to check i...j we can just make 1..i-1 the root

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
