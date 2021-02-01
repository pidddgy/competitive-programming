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
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()

void solve() {
    string s;
    cin >> s;

    int cnt = 0;
    for(char x: s) if(x == '0') cnt++;
    if(cnt == sz(s)) {
        for(int i = 1; i <= sz(s)+1; i++) {
            cout << 1;
        }
    } else {
        bool add = false;
        bool less = false;
        for(char x: s) {
            if(x == s[0]) continue;
            if(x < s[0]) {
                less = true;
                break;
            }
            if(x > s[0]) add = true;
        }

        if(!less) add = true;

        if(add and s[0] == '9')  {
           for(int i = 1; i <= sz(s)+1; i++) {
                cout << 1;
            } 
        } else {
            for(int i = 1; i <= sz(s); i++) {
                char x = s[0]+add;
                cout << x;
            }
        }
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
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
