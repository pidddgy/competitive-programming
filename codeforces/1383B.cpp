// https://codeforces.com/problemset/problem/1383/B

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

const int maxn = 100500;

int n;
int a[maxn];

void solve() {
    cin >> n;
    
    int x = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        x ^= a[i];
    }

    if(x == 0) {
        cout << "DRAW" << endl;
    }

    for(int i = 30; i >= 0; i--) {
        int b = (1 << i);
        if(x & b) {
            vector<int> cnt(2);

            for(int j = 1; j <= n; j++) {
                bool set = ((1<<i) & (a[j]));

                cnt[set]++;
            }

            if(cnt[1] % 4 == 3 and cnt[0] % 2 == 0) {
                cout << "LOSE" << endl;
            } else {
                cout << "WIN" << endl;
            }
            break;
        }
    }


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

x mod 4, we use 4 because we want to maintian parity after both people move

look for cases where players can copy each other

only case where player 2 can copy player 1 to win is if there's even number of 0 and x mod 4 is 3

realize the part where we iterate from 30...0, guess the mod 4 bit

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
