// Link

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
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> cnt;

    int sq = 0;
    int t = 0;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        cnt[a]++;

        if(cnt[a] % 4 == 0) {
            sq++;
            t--;
        } else if(cnt[a] % 2 == 0) {
            t++;
        }
    }

    int q;
    cin >> q;

    while(q--) {
        char type;
        int a;
        cin >> type >> a;

        if(type == '+') {
            cnt[a]++;
            if(cnt[a]%4 == 0) {
                sq++;
                t--;
            } else if(cnt[a] % 2 == 0) {
                t++;
            }
        } else if(type == '-') {
            if(cnt[a]%4 == 0) {
                sq--;
                t++;
            } else if(cnt[a] % 2 == 0) {
                t--;
            }
            cnt[a]--;
        }

        if((sq >= 2) or (sq == 1 and t >= 2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    
}

/*

keep track of planks w >= 4 occurences

keep track of planks w >= 2 occurences
    -> subtract one because of the first

always create as many squares as possible

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
