// https://codeforces.com/contest/777/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n+1][m+1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j]; 
        }
    }

    int dec[n+1][m+1];
    for(int i = 1; i <= m; i++) {
        dec[1][i] = 0;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] < a[i-1][j]) {
                dec[i][j] = i;
            } else {
                dec[i][j] = dec[i-1][j]; 
            }
        }
    }

    int k;
    cin >> k;

    if(n < m) {
        bool ans[n+1][n+1];
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                ans[i][j] = false;
                for(int l = 1; l <= m; l++) {
                    if(dec[i][l] >= dec[j][l]) {
                        ans[i][j] = true;
                    }
                }
            }
        }

        for(int i = 1; i <= k; i++) {
            int l, r;
            cin >> l >> r;

            // cout << l << "......" << r << endl;
            if(ans[l][r]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

    } else {
        for(int i = 1; i <= k; i++) {
            int l, r;
            cin >> l >> r;

            string ans = "No";
            for(int j = 1; j <= m; j++) {
                if(dec[l][j] >= dec[r][j]) {
                    ans = "Yes";
                }
            }

            cout << ans << endl;
        }        
    }


}