// https://codeforces.com/contest/1268/problem/A

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
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    s = "."+s;

    string t = s;

    for(int i = k+1; i <= n; i++) {
        t[i] = t[i-k];
    }

    cout << n << endl;
    if(t >= s) {
        for(int i = 1; i <= n; i++) {
            cout << t[i];
        }
        cout << endl;
    } else {
        for(int i = k; i >= 1; i--) {
            if(t[i] == '9') t[i] = '0';
            else {
                t[i]++;
                break;
            }
        }

        for(int i = k+1; i <= n; i++) {
            t[i] = t[i-k];
        }

        for(int i = 1; i <= n; i++) {
            cout << t[i];
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
