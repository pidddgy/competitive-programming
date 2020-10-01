// https://codeforces.com/contest/917/problem/A

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

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = sz(s);

    s = "."+s;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int score = 0, qmarks = 0;
        for(int j = i; j <= n; j++) {
            if(s[j] == '(') score++;
            else if(s[j] == ')') score--;
            else if(s[j] == '?') qmarks++;
            else assert(false);
            
            if(score < 0) break;            

            if(qmarks > score) {
                score++;
                qmarks--;
            }

            if(qmarks >= score) {
                ans++;
            }
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
