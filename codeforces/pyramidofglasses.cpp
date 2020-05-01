// https://codeforces.com/contest/676/problem/B

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define ld long double
using namespace std;

ld a[500][500];
int main() {
    int n, t;
    cin >> n >> t;

    const int sr = 250;
    const int sc = 1;
    for(int i = 1; i <= t; i++) {
        cerr << "i is " << i << endl;
        a[sr][sc] += 1;
        for(int j = 1; j <= n; j++) {
            int l = sr-j-1;
            int r = sr+j-1;
            int c = sc+j-1;

            for(int k = l; k <= r; k += 2) {
                if(a[k][c] > 1.0) {
                    cerr << k << " " << c << " has more than 1" << endl;

                    if(c+1 <= n) {
                        ld o = a[k][c] - 1;
                        
                        cerr << setprecision(10) << "passing on " << o << " to " << k-1 << " " << c+1 << " and " << k+1 << " " << c+1 << endl;
                        a[k-1][c+1] += o/2;
                        a[k+1][c+1] += o/2;
                    }
                    a[k][c] = 1.0;
                }
            }
        }
        cerr << endl;
    }

    int ans = 0;
    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            if(a[i][j] >= 1.0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}