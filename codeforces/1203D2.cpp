// https://codeforces.com/contest/1203/problem/D2

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

const int maxn = 200500;

int n;
string s, t;
int pre[maxn], suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    n = sz(s);

    s = "."+s;

    string cpy = t;
    reverse(all(cpy));

    int cur = 0;
    for(int i = 1; i <= n; i++) {
        if(sz(cpy) and s[i] == cpy.back()) {
            cpy.pop_back();
            cur++;
        }
        pre[i] = cur;
    }

    cpy = t;
    cur = 0;

    for(int i = n; i >= 1; i--) {
        if(sz(cpy) and s[i] == cpy.back()) {
            cpy.pop_back();
            cur++;
        }

        suf[i] = cur;
    }

    for(int i = 1; i <= n; i++) {
        cerr << pre[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        cerr << suf[i] << " ";
    }
    cerr << endl;

    int ans = 0;
    int r = 1;
    for(int l = 0; l <= n; l++) {
        int need = sz(t)-pre[l];

        watch(l)
        watch(need)


        if(need == 0) {
            ans = max(ans, n-l);
            continue;
        }

        while(suf[r+1] >= need and r <= n+1) r++;
        watch(r)


        ans = max(ans, r-l-1);
        cerr << endl;
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
