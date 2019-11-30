// https://dmoj.ca/problem/cco14p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N; 
    cin >> N;

    char a[N+1][N+1];
    int b[N+1][N+1];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i = N; i >= 1; i--) {
        for(int j = 1; j <= N; j++) {
                
            if(a[i][j] == '#') {
                b[i][j] = 1;
            }
            if(i+1 <= N and j+1 <= N and j-1 >= 1) {
                if(a[i][j] == '#')
                if(a[i+1][j] == '#' and a[i+1][j+1] == '#' and a[i+1][j-1] == '#') {
                    b[i][j] += min(b[i+1][j], min(b[i+1][j-1], b[i+1][j+1]));
                }
            }

            ans += b[i][j];

        }
    }

    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;

}