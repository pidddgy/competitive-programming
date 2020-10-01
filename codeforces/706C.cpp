// https://codeforces.com/contest/706/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ll long long

const int maxn = 100500LL;
const ll INF = 5000050000000000;

// 0 == stay, 1 = flip
ll dp[maxn][2];
string a[maxn];
string rev[maxn];
ll c[maxn];

bool prefix(string x, string y) {
    for(int i = 0; i < x.size(); i++) {
        if(x[i] != y[i]) {
            return false;
        }
    }
    return true;
}
bool lexcmp(string x, string y) {
    if(x == y) return true;
    if(x.size() < y.size() and prefix(x, y)) {
        return true;
    } else if(y.size() < x.size() and prefix(y, x)) {
        return false;
    }

    for(int i = 0; i < min(x.size(), y.size()); i++) {
        if(x[i] != y[i]) {
            return x[i] < y[i];
        }
    }

    
    // return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);


    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j <= 1; j++) {
            dp[i][j] = INF;
        }
    }


    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        a[i] = s;
        reverse(s.begin(), s.end());
        rev[i] = s;
    }

    dp[n][0] = 0LL;
    dp[n][1] = c[n];
    for(int i = n-1; i >= 1; i--) {
        if(lexcmp(a[i], a[i+1])) {
            dp[i][0] = min(dp[i][0], dp[i+1][0]);
        }

        if(lexcmp(a[i], rev[i+1])) {
            dp[i][0] = min(dp[i][0], dp[i+1][1]);
        }

        if(lexcmp(rev[i], a[i+1])) {
            dp[i][1] = min(dp[i][1], dp[i+1][0]+c[i]);
        }

        if(lexcmp(rev[i], rev[i+1])) {
            dp[i][1] = min(dp[i][1], dp[i+1][1]+c[i]);
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 0; j <= 1; j++) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    if(min(dp[1][0], dp[1][1]) == INF) {
        cout << -1 << endl;
    } else {
        cout << min(dp[1][0], dp[1][1]) << endl;
    }
}

/*


10

1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
zaaaaaaaaaa
yaaaaaaaaa
xaaaaaaaa
waaaaaaa
vaaaaaa
uaaaaa
taaaa
saaa
raa
qa

*/