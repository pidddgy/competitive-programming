// https://codeforces.com/contest/375/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxnm = 5005;

int a[maxnm][maxnm];
int suf[maxnm][maxnm];
int n, m;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        s = "."+s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j]-'0';
        }
    }

    for(int i = 1; i <= n; i++) {
        int cur = 0;
        for(int j = 1; j <= m; j++) {
            if(a[i][j]) {
                cur++;
            } else {
                cur = 0;
            }

            suf[i][j] = cur;
            cerr << suf[i][j] << " ";
        }
        cerr << endl;
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        vector<int> col;
        col.emplace_back(INT_MAX);
        for(int j = 1; j <= n; j++) {
            col.emplace_back(suf[j][i]);
        }
        sort(col.begin(), col.end(), greater<int>());

        cerr << "on column " << i << endl;
        for(int j = 1; j <= n; j++) {
            // cerr << "row " << j << " would give " << col[j]*j << endl;
            cerr << col[j] << " ";
            ans = max(ans, col[j]*j);
        }
        cerr << endl;
    }

    cout << ans << endl;
}