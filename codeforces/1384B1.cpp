// https://codeforces.com/contest/1384/problem/B1

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

const int maxk = 305;
const int maxn = 305;

// i, j = possible to get to index i with p[i] = j
bool dp[maxn][maxk*2];
vector<int> p;
int a[maxn];
int n, k, l;

int mod(int num) {
    return (num+(2*k))%(2*k);
}

set<int> t[maxk];
void solve() {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxk*2; j++) {
            dp[i][j] = false;
        }
        a[i] = 0;
    }
    p.clear();

    cin >> n >> k >> l;
    string ans = "Yes";
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n+1] = -(1e18);

    for(int i = 0; i < k*2; i++) {
        dp[0][i] = true;
    }

    for(int i = 0; i <= k; i++) {
        p.push_back(i);
    }

    for(int i = k-1; i >= 1; i--) {
        p.push_back(i);
    }

    for(int x: p) {
        cerr << x << " ";
    }
    cerr << endl;
    cerr << endl;

    // for(int ree = 0; ree <= 10; ree++)
    for(int j = 0; j < 2*k; j++) {
        cerr << p[j] << " ";
    }
    cerr << endl;
    for(int i = 1; i <= n+1; i++) {
        for(int j = 0; j < 2*k; j++) {
            int h = mod(j-1);
            int ree = p[j];

            if(i == 3 and j == 5) {
                cerr << "transition from " << h << endl;
                watch(a[i])
                watch(ree)
                watch(a[i]+ree)
            }
            // cerr << "if on time " << j << " at " << i << " height " << a[i]+ree << endl;

            if(a[i]+ree <= l and dp[i-1][h]) {
                for(int m = 0; m < 2*k; m++) {
                    int ind = mod(j+m);

                    int height = a[i]+p[ind];
                    if(height > l) break;

                    dp[i][ind] = true;
                }
            }

            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    watch(dp[1][8])
    watch(dp[2][9])
    watch(dp[3][10])
    watch(dp[4][11])
    watch(dp[5][0])
    watch(dp[6][1])
    watch(dp[7][2])
    watch(dp[8][3])
    watch(dp[9][4])


    bool ok = false;
    for(int j = 0; j < 2*k; j++) {
        ok |= dp[n+1][j];
    }

    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}