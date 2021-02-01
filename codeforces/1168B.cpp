// https://codeforces.com/contest/1168/problem/B

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


bool f(string s) {
    for(int i = 0; i < sz(s); i++) {
        for(int j = i+1; j < sz(s); j++) {
            int k = j+(j-i);

            if(k < sz(s))
            if(s[i] == s[j] and s[j] == s[k]) {
                return true;
            }
        }
    }

    return false;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = sz(s);

    s = "."+s;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        string cur;
        for(int j = i; j <= min(i+15, n); j++) {
            cur += s[j];
            ans += f(cur);
        }

        ans += n-min(i+15, n);
    }

    cout << ans << endl;
}

/*

0011010011

1 2 3 4 5
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
