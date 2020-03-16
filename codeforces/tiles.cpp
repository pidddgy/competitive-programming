// http://codeforces.com/contest/1178/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

long long a[1005][1005];
int main() {
    #define int long long
    int w, h;
    cin >> w >> h;

    a[1][1] = 4;
    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= h; j++)  {
            if(i == 1 && j == 1) continue;

            if(i == 1) {
                a[i][j] = a[i][j-1]*2;
                a[i][j] %= 998244353;
            }

            else if(j == 1) {
                a[i][j] = a[i-1][j]*2;
                a[i][j] %= 998244353;
            }

            else {
                a[i][j] = a[i-1][j-1]*4;
                a[i][j] %= 998244353;
            }
        }

    }

    // for(int i = 1; i <= w; i++) {
    //     for(int j = 1; j <= h; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << a[w][h] % 998244353 << endl;
}