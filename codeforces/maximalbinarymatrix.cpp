// https://codeforces.com/contest/803/problem/A

#include <bits/stdc++.h>
using namespace std;

bool grid[200][200];
int main() {
    int n, k;
    cin >> n >> k;

    if(k > n*n) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                if(k) {
                    grid[i][i] = 1;
                    k--;
                }
            }

            if(k >= 2) {
                if((!grid[i][j]) and (!grid[j][i])) {
                    grid[i][j] = 1;
                    grid[j][i] = 1;
                    k -= 2;
                }
            }
        }
    }

    if(k != 0) {
        cout << -1 << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }


}