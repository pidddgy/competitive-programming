// https://codeforces.com/contest/922/problem/D

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

vector<string> strs;

int f(string ree) {
    int hugs = 0, sum = 0;
    for(char x: ree) {
        if(x == 's') hugs++;
        else sum += hugs;
    }

    return sum;
}

struct Compare {
    bool operator()(string l, string r) {
        return f(l+r) > f(r+l);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        string x;
        cin >> x;

        strs.emplace_back(x);
    }

    sort(all(strs), Compare());

    int hugs = 0, ans = 0;
    for(string x: strs) {
        for(char y: x) {
            if(y == 's') hugs++;
            else ans += hugs;

            cerr << y;
        }
    }
    cerr << endl;

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
