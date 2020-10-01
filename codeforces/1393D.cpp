// https://codeforces.com/contest/1393/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

int psa[5050][5050];
char a[5050][5050];
const int SHIFT = 2000;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }
    
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 5050; j++) {
            for(int k = 0; k < 5050; k++) {
                psa[j][k] = 0;
            }
        }

        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                if(a[j][k]-'a' == i) {
                    psa[j][k]++;
                }
                psa[j][k] += 
            }
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
