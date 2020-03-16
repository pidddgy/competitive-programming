// https://codeforces.com/contest/1059/problem/B

#include <bits/stdc++.h>
#define cerr if(false) cerr
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    char a[n+50][m+50];
    char ans[n+50][m+50];
    for(int i = 0; i < n+50; i++) {
        for(int j = 0; j < m+50; j++) {
            a[i][j] = '?';
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans[i][j] = a[i][j];
        }
    }

    for(int o = 0; o <= 10; o++)
    for(int i = 2; i <= n-1; i++) {
        for(int j = 2; j <= m-1; j++) {
            int cnt = 0;
            cnt += a[i-1][j] == '#';
            cnt += a[i-1][j+1] == '#';
            cnt += a[i-1][j-1] == '#';

            cnt += a[i][j+1] == '#';
            cnt += a[i][j-1] == '#';

            cnt += a[i+1][j] == '#';
            cnt += a[i+1][j+1] == '#';
            cnt += a[i+1][j-1] == '#';

            if(cnt == 8) {
                ans[i-1][j] = '.';
                ans[i-1][j+1] = '.';
                ans[i-1][j-1] = '.';

                ans[i][j+1] = '.';
                ans[i][j-1] = '.';

                ans[i+1][j] = '.';
                ans[i+1][j+1] = '.';
                ans[i+1][j-1] = '.';
            }

        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cerr << ans[i][j] << " ";
            if(ans[i][j] == '#') {
                cout << "NO" << endl;
                return 0;
            }
        }
        cerr << endl;
    }

    cout << "YES" << endl;
}