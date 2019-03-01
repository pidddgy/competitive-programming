#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
#define aand &&
#define minv -2000000
using namespace std;

ll toInt (string n) {
    ll p = pow(10, n.size()-1);
    int r = 0;
    if(n[0] == '-') {
        for(int i = 1; i < n.size(); i++) {
            r += (n[i]-'0') * p;
            p /= 10;
        }
    } else {
        for(int i = 1; i < n.size(); i++) {
            r += (n[i]-'0') * p;
            p /= 10;
        }
    }

    watch(r)
    if(n[0] == '-') r *= -1;

    return r;
}
int main() {
    cout << toInt("12") << endl;
    // ll g[3][3];

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         string a;
    //         cin >> a;

    //         if(a == "X") g[i][j] = minv;
    //         else {
    //             g[i][j] = toInt(a);
    //         }
    //     }
    // }

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //        if(g[i][j] == minv) {
    //             // Check row

    //             if(j == 0 aand g[i][1] != minv aand g[i][2] != minv) {
    //                 g[i][j] = g[i][1] - (g[i][2] - g[i][1]);
    //                 continue;
    //             } else if (j == 1 aand g[i][0] != minv aand g[i][2] != minv) {
    //                 g[i][j] = g[i][0] + (g[i][2] - g[i][0]) / 2;
    //                 continue;
    //             } else if(j == 2) {
    //                 g[i][j] = g[i][1] + (g[i][1] - g[i][0]);
    //                 continue;
    //             }


    //            // Check column
    //            if(i == 0 aand g[1][j] != minv aand g[2][j] != minv) {
    //                 g[i][j] = g[2][j] - g[1][j];
    //                 continue;
    //             } else if (i == 1 aand g[0][j] != minv aand g[2][j] != minv) {
    //                 g[i][j] = g[0][j] + (g[2][j] - g[0][j]) / 2;
    //                 continue;
    //             } else if(i == 2) {
    //                 g[i][j] = g[0][j] + g[1][j];
    //                 continue;
    //             }

    //        } 
    //     }
    // }

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}