// https://codeforces.com/contest/1372/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        pii ans = {1, n-1};

        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0) {
                int a = i;
                // if(a == 9) cout << "sdfsdfsf" << endl;
                int b = n-i;

                // watch(lcm(a, b))
                if(lcm(a, b) < lcm(ans.fi, ans.se)) {
                    ans = pii(a, b);
                }

                int c = n/i;
                int d = n-c;

                if(lcm(c, d) < lcm(ans.fi, ans.se)) {
                    ans = pii(c, d);
                }
            }
        }

        cout << ans.fi << " " << ans.se << endl;
    }
}

// 11 44
// 15 30
// 5 20
// 31 31
// 33 33
// 11 22
// 4 4
// 30 30
// 24 24
// 43 43
// 1 17
// 27 54
// 38 38
// 7 14
// 1 1
// 16 16
// 50 50
// 25 50
// 1 19
// 23 23
// 3 3
// 1 23
// 39 39
// 21 21
// 27 27
// 1 89
// 9 9
// 44 44
// 13 52
// 40 40
// 17 17
// 34 34
// 47 47
// 1 11
// 1 37
// 1 83
// 1 43
// 17 34
// 2 2
// 19 19
// 1 97
// 46 46
// 12 12
// 32 32
// 7 28
// 1 47
// 19 76
// 35 35
// 1 29
// 28 28