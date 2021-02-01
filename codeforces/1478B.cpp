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
    int n, d;
    cin >> n >> d;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        string ans = "NO";
        for(int j = 0; j <= 11; j++) {
            int x = d*j;

            if(x <= a) {
                int rem = x-a;
                bool f = false;

                for(char x: to_string(rem)) if(x == '0'+d) f = true;

                if(rem == 0 or f)
                    ans = "YES";
            }
        }

        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*
some amt of 7 + some amount of 10

up to 11d
*/


// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?