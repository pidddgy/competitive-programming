// https://codeforces.com/contest/691/problem/C

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
    cin.tie(0);

    string s;
    cin >> s;

    int pos = -1, dpos = -1;
    for(int i = 0; i < sz(s); i++) {
        if(s[i] == '.' and dpos == -1) dpos = i;
        if(s[i] != '0' and s[i] != '.' and pos == -1) pos = i;
    }

    if(dpos != -1) {
        s.erase(dpos, 1);
    } else {
        dpos = sz(s);
    }

    int exp = dpos-pos;
    if(exp > 0) exp--;

    for(int i = 0; i < 2; i++) {
        while(s.back() == '0') s.pop_back();
        reverse(all(s));
    }

    if(sz(s) > 1) s.insert(1, ".");

    cout << s;
    if(exp != 0) {
        cout << "E" << exp;
    }
    cout << endl;
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
