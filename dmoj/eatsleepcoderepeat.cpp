// https://dmoj.ca/problem/wac3p2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int D;
    cin >> D;

    for(int i = 0; i < D; i++) {
        int h;
        cin >> h;

        // int ma = 0; 

        // for(int i = 1; i <= h; i++) {
        //     for(int j = 1; j <= h; j++) {
        //         for(int k = 1; k <= h; k++) {
        //             if(i+j+k == h)
        //             ma = max(ma, i*j*k);
        //         }
        //     }
        // }

        // cout << ma << endl;
        int a = h/3;

        h -= a;

        int b = h/2;
        int c = h-b;

        cout << a * b * c << endl;

    }
}