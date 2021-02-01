// https://codeforces.com/contest/1451/problem/C

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
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    vector<int> cnta(40);
    vector<int> cntb(40);

    for(char x: a) cnta[x-'a']++;
    for(char x: b) cntb[x-'a']++;
    
    string ans = "Yes";
    int extra = 0;
    for(int i = 0; i < 26; i++) {
        if(cnta[i] > cntb[i]) {
            int sur = cnta[i]-cntb[i];

            if((sur%k == 0)) {
                extra += sur;
            } else {
                ans = "No";
            }
        } else if(cntb[i] > cnta[i]) {
            int need = cntb[i]-cnta[i];

            if((need % k == 0) and (need <= extra)) {
                extra -= need;
            } else {
                ans = "No";
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

think about pushing letters ahead

brute force / check if amount we need is divisible by k
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?