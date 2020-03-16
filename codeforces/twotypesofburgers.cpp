// http://codeforces.com/contest/1207/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    for(int q = 1; q <= t; q++) {
        int b, p, f;
        cin >> b >> p >> f;

        int h, c;
        cin  >> h >> c;

        if(h > c) {
            int tot = 0;
            while(b >= 2 and p) {
                b -= 2;
                p--;
                tot += h;
            }

            while(b >= 2 and f) {
                b -= 2;
                f--;
                tot += c;
            }

            cout << tot << endl;
        } else {
            int tot = 0;
             while(b >= 2 and f) {
                b -= 2;
                f--;
                tot += c;
            }
            while(b >= 2 and p) {
                b -= 2;
                p--;
                tot += h;
            }
            cout << tot << endl;
        }
    }


}