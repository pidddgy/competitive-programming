// https://codeforces.com/contest/825/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string grid[50];

    for(int i = 1; i <= 10; i++) {
        string row;
        cin >> row;

        row = "."+row;
        assert(row.size() == 11);

        grid[i] = row;
    }
    string ans = "NO";
    // check row
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 6; j++) {
            int plrow = 0;
            int plcol = 0;
            for(int k = 0; k <= 4; k++) {
                if(grid[i][j+k] == 'O') {
                    plrow = 9999;
                } else if(grid[i][j+k] == '.') {
                    plrow++;
                }

                if(grid[j+k][i] == 'O') {
                    plcol = 9999;
                } else if(grid[j+k][i] == '.') {
                    plcol++;
                }
            }

            if((plrow == 1) or (plcol == 1)) {
                cerr << i << "," << j << endl;
                watch(plrow)
                watch(plcol)
                cerr << endl;
                ans = "YES";
            }
        }
    }

    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= 6; j++) {
            int pldiag = 0;
            for(int k = 0; k <= 4; k++) {
                if(grid[i+k][j+k] == 'O') {
                    pldiag = 9999;
                    break;
                } else if (grid[i+k][j+k] == '.') {
                    pldiag++;
                }
            }

            if(pldiag == 1) {
                ans = "YES";
            }
        }
    }

    for(int i = 1; i <= 6; i++) {
        for(int j = 5; j <= 10; j++) {
            int pldiag = 0;
            for(int k = 0; k <= 4; k++) {
                if(grid[i+k][j-k] == 'O') {
                    pldiag = 9999;
                    break;
                } else if (grid[i+k][j-k] == '.') {
                    pldiag++;
                }
            }

            if(pldiag == 1) {
                ans = "YES";
            }
        }
    }

    cout << ans << endl;

}