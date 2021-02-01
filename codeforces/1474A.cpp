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
    int n;
    cin >> n;

    string b;
    cin >> b;

    string a = "1";

    for(int i = 1; i < n; i++) {
        int lst = (b[i-1]-'0') + (a.back()-'0');
        if(lst == 2) {
            if(b[i] == '0') a += '1';
            else a += '0';
        } else if(lst == 1) {
            if(b[i] == '0') a += '0';
            else a += '1';
        } else if(lst == 0) {
            a += '1';
        }
    }

    cout << a << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

make first one 1 or 2

if last one is 2 then make this one 1
if last one is 1 then make this one 2 or 0
if last one is 0 then make this 1 or 2

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
