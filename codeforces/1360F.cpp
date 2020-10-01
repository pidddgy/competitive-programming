// Linkhttps://codeforces.com/problemset/problem/1360/F

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

int n, m;
char a[15][15];
bool dp[15][1030];

void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        a[i][0] = '?';
        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }    

    for(int mask = 0; mask <= (1 << n) - 1; mask++) {
        dp[m][mask] = true;
    }

    for(int i = m; i >= 1; i--) {
        for(int mask = 0; mask <= (1 << n) - 1; mask++) {
            if(!dp[i][mask]) continue;

            for(int j = 0; j < 26; j++) {
                int newmask = mask;
                bool ok = true;

                for(int k = 1; k <= n; k++) {
                    if(a[k][i]-'a' != j) {
                        if(!(mask & (1 << (k-1)))) ok = false;
                        newmask &= ~(1 << (k-1));
                    }
                }            

                if(ok) {
                    cerr << "pushing from " << i << "," << bitset<10>(mask) << " to " << i-1 << "," << bitset<10>(newmask) << " with letter " << j << endl;
                    dp[i-1][newmask] = true;
                }
            }
        }
    }

    bool possible = false;
    for(int j = 0; j <= (1 << n) - 1; j++) {
        if(dp[0][j]) {
            // cerr << bitset<10>(j) << " is ok" << endl;
            possible = true;
            break;
        }
    }

    if(!possible) {
        cout << -1 << endl;
    } else {
        int mask = 0;
        for(int i = 0; i < m; i++) {
            cerr << "on move " << i << endl;
            bool found = false;
            for(int j = 0; j < 26; j++) {
                bool ok = true;
                int newmask = mask;


                for(int k = 1; k <= n; k++) {
                    if(a[k][i+1]-'a' != j) {
                        if(mask & (1 << (k-1))) ok = false;
                        newmask |= (1 << (k-1));
                    }
                }     
                cerr << "picking " << j << " results in " << bitset<10>(newmask) << endl;

                if(ok and dp[i+1][newmask]) {
                    cout << (char)(j+'a');
                    mask = newmask;
                    found = true;
                    break;
                }
            }

            assert(found);
        }

        cout << endl;
    }
    // clear everything at the end
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            a[i][j] = '?';
        }

        for(int j = 0; j < 1030; j++) {
            dp[i][j] = false;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();    
}

/*

dp on bitmask
bool dp[i][j] = if we can get to mask j on the i'th move

for move in 1..m
    for mask in 0...1024
        for letter in 'a'...'z'
            newmask = mask
            ok = true
            for each string:
                check that mask is not already toggled, if toggled then ok = false

            if ok then push up

time complexity: O(t*m*1024*26*n)
    -> 26 624 000 operations

restore the construction through at each step, pick any letter that works



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
