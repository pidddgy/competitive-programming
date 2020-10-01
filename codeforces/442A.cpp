// https://codeforces.com/contest/442/problem/A

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

set<pii> p;
const int maxn = 105;

int col[maxn], num[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        int c;
        if(s[0] == 'R') c = 0;
        if(s[0] == 'G') c = 1;
        if(s[0] == 'B') c = 2;
        if(s[0] == 'Y') c = 3;
        if(s[0] == 'W') c = 4;

        p.emplace(c[i], s[1]-'1');
    }


    int ans = LLONG_MAX;

    for(int tc = 0; tc <= (1 << 5) - 1; tc++) {
        for(int tn = 0; tn <= (1 << 5) - 1; tn++) {
            vector<int> hints;
            for(int i = 0; i < 5; i++) {
                if(tc & (1 << i)) hints.emplace_back(i);
                if(tn & (1 << i)) hints.emplace_back(-i);
            }
            for(int i = 1; i <= n; i++) {
                mask[i] = 0;
                for(int h: hints) {

                }
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
