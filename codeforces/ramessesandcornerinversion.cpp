// https://codeforces.com/contest/1119/problem/C

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

    int b[n+1][m+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    for(int i = 1; i <= n-1; i++) {
        for(int j = 1; j <= m-1; j++) {
            if(a[i][j] == 1) {
                a[i][j] ^= 1;
                a[i][j+1] ^= 1;
                a[i+1][j] ^= 1;
                a[i+1][j+1] ^= 1;
            }

            if(b[i][j] == 1) {
                b[i][j] ^= 1;
                b[i][j+1] ^= 1;
                b[i+1][j] ^= 1;
                b[i+1][j+1] ^= 1;
            }
        }
    }

    bool good = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] != b[i][j]) good = false;
        }
    }

    if(good) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
