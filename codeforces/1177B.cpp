// https://codeforces.com/contest/1177/problem/B

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    // i = number of digits
    int p = 10;
    int ree = 1;
    for(int i = 1; i <= 20; i++) {
        int u = p-1;
        int a = u-(p/10 - 1);

        int tot = a*i;

        if(k > tot) {
            k -= tot;
        } else {
            int use = (k-1)/i;
            k -= use*i;
            string s = "." + to_string(ree+use);
            cout << s[k] << endl;
            break;
        }

        ree = p;
        p *= 10;
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
