// https://dmoj.ca/problem/bts19p2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int X, Y, H, V, T;



int main() {
    cin >> X >> Y >> H >> V >> T;

    for(int i = 0; i <= 3162; i++) {
        for(int j = 0; j <= 3162; j++) {
            // i == move a, j == move b

            int x = i + (j*2);
            int y = (i*2)+ (j);

            if(x >= X and x < X+H) {
                if(y >= Y and y < Y+V) {
                    if(i + j < T) {
                    cout << "YES" << endl;
                    return 0;
                    }

                }
            }
        // cout << endl;
        }
    }

    cout << "NO" << endl;
}