// https://codeforces.com/contest/990/problem/D

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

const int maxn = 1050;

int n, a, b;
int ans[maxn][maxn];

void no() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;

    if(min(a, b) > 1) no();
    if((n == 2 or n == 3) and a == 1 and b == 1) no();

    int c = 1, d = 0;

    if(b != 1) {
        swap(a, b);
        swap(c, d);
    }
    
    for(int i = 1; i <= n; i++) {
        ans[i][i] = 0;
        for(int j = 1; j <= n; j++) {
            if(i != j) {
                ans[i][j] = ans[j][i] = d;
            } 
        }
    }

    for(int i = a; i+1 <= n; i++) {
        ans[i][i+1] = ans[i+1][i] = c;
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
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
