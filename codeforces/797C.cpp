// https://codeforces.com/contest/797/problem/C

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

const int maxn = 100500;

string s;
int n;

// suffix min
char mi[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = sz(s);

    s = "."+s;

    stack<char> S;

    mi[n+1] = CHAR_MAX;
    for(int i = n; i >= 1; i--) {
        mi[i] = min(mi[i+1], s[i]);
    }

   string ans;

    int ind = 1;

    while(ind <= n) {
        if(S.empty()) {
            S.push(s[ind]);
            ind++;
            continue;
        }

        if(mi[ind] < S.top()) {
            S.push(s[ind]);
            ind++;
        } else {
            ans += S.top();
            S.pop();
        }
    }

    while(sz(S)) {
        ans += S.top();
        S.pop();
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
