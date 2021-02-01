// https://codeforces.com/contest/998/problem/C

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

int go(int n) {
    set<int> S;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= n; k++) {
                for(int l = 0; l <= n; l++) {
                    if(i + j + k + l != n) continue;

                    int num = 0;
                    num += i;
                    num += j*5;
                    num += k*10;
                    num += l*50;

                    S.emplace(num);
                }
            }
        }
    }
    return sz(S);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    
    if(n <= 30) {
        cout << go(n) << endl;
        return 0;
    }

    int x = go(30);

    cout << x + (n-30)*49 << endl;
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