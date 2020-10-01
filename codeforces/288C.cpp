// https://codeforces.com/contest/288/problem/C

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

const int maxn = (int)1e6+500;

int ans[maxn];

int msb(int num) {
    for(int i = 20; i >= 0; i--) {
        if((1LL << i) & num) {
            return i;
        }
    }

    assert(false);
    return -1;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int cpy = n;

    while(n > 0) {
        int lg = msb(n);

        for(int i = 0; i <= n; i++) {
            int a = (1 << (lg+1));
            ans[i] = (a-1)-i;
        }

        int next = -1;
        for(int i = 0; i <= n; i++) {
            if(ans[i] > n) next = i;
        }

        n = next;
    }

    if(!n) ans[0] = 0;

    cout << cpy*(cpy+1) << endl;
    for(int i = 0; i <= cpy; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

/*

each number has a unique complement <= i that will be the "flipped" version of it so we can make n

give each flipped number the biggest prefix of 1s as possible

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
