// https://codeforces.com/contest/1428/problem/B

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

const int maxn = 300500;

int n;

int mod(int num) {
    return (num+n)%n;
}
void solve() {
    cin >> n;

    string s;
    cin >> s;    

    bool both = false;
    set<char> S;
    for(char x: s) {
        if(x == '-') both = true;
        S.emplace(x);
    }

    if((sz(S) == 2 and both) or (sz(S) == 1)) {
        cout << n << endl;
        return;
    }

    int ind = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != '-') {
            ind = i;
            break;
        }
    }   

    watch(ind)
    int ans = 0;
    int run = 0;
    for(int i = 0; i < n+1; i++) {
        int idx = mod(ind+i);

        watch(idx)

        if(s[idx] == '-') run++;
        
        if(s[idx] != '-' and run) {
            ans += run+1;
            run = 0;
        }


    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

two cases, segment of - or one big cycle

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
