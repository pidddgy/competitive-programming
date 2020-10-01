// https://codeforces.com/contest/65/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

const int maxn = 1500;
int a[maxn];
int ans[maxn]; 

void no() {
    cout << "No solution" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        bool f = false;
        for(int j = 1000; j <= 2011; j++) {
            int edit = 0;
            int p = 1;
            for(int k = 0; k < 4; k++) {
                if((a[i]/p)%10 != (j/p)%10) {
                    edit++;
                }
                p *= 10;
            }

            bool ok = (edit <= 1);
            if(i > 1 and j < ans[i-1]) ok = false;

            if(ok) {
                f = true;
                ans[i] = j;
                break;
            }
        }

        if(!f) {
            no();
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
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
