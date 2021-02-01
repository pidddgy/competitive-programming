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
string s;
int n;

char f(int ind) {
    cerr << "getting index " << ind << endl;
    int k = 0;
    int len = n;

    while(len < ind) {
        len *= 2;
        k++;
    }
    watch(len)

    if(k == 0) return s[ind];

    int half = len/2;
    watch(half)
    if(ind == half+1) return f(ind-1);
    else return f(ind-half-1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);

    cin >> s;
    n = sz(s);

    if(n == 1) {
        cout << s[0] << endl;
        return 0;
    }
    s = "."+s;

    int x;
    cin >> x;

    cout << f(x) << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
