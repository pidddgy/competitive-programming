// https://codeforces.com/contest/1421/problem/C

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

bool pal(string hugs) {
    string cute = hugs;
    reverse(all(cute));

    return cute == hugs;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    cout << 3 << endl;
    int n = sz(s);
    cout << "L 2" << endl;
    n++;

    cout << "R 2" << endl;
    n += n-2;

    cout << "R " << n-1 << endl;
}

/*


have to eventually "collect" original leftmost and original rightmost

L 2


axyz

xaxyz

xaxyzyxa

xaxyzyxax





*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
