// https://codeforces.com/contest/1384/problem/B1

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

const int maxk = 105;
const int maxn = 105;

// i, j = possible to get to index i with p[i] = j
bool dp[maxn][maxk*2];
int a[maxn];
int n, k, l;

int mod(int n) {
    return (n+(2*k))%(2*k);
}
void solve() {
    cin >> n >> k >> l;
    watch(mod(3))
    string ans = "Yes";
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= maxk*2; i++) {
        dp[0][i] = true;
    }

    for(int i = 1; i <= n+1; i++) {
        for(int j = 0; j < 2*maxk; j++) {
            if(j > l) continue;

            int h = mod(j-1);
            int h2 = mod(j+1);

            if(a[i-1]+h <= l) {
                dp[i][j] |= dp[i-1][h];
                if(dp[i-1][h]) {
                    cerr << i << " " << j << " is possible because " << i-1 << " " << h << " is possible" << endl;
                } 
            }

            if(a[i-1]+h2 <= l) {
                if(dp[i-1][h2]) {
                    cerr << i << " " << j << " is possible because " << i-1 << " " << h2 << " is possible" << endl;
                }
                dp[i][j] |= dp[i-1][h2];
            }

        }
    }

    bool ok = false;
    for(int j = 0; j < 2*maxk; j++) {
        if(dp[n+1][j]) {
            watch(n+1)
            cerr << "hit at " << j << endl;
        }
        ok |= dp[n+1][j];
    }

    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

void clear() {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxk*2; j++) {
            dp[i][j] = false;
        }
        a[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        clear();
        solve();
    }
}