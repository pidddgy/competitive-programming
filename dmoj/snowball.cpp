// http://codeforces.com/contest/1099/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    // Weight and height of snowball
    int w, h;
    cin >> w >> h;

    // Weight and height of stone 1
    int ws1, hs1;
    cin >> ws1 >> hs1;

    // Stone 2
    int ws2, hs2;
    cin >> ws2 >> hs2;

    for(;;) {

        w += h;

        if(h == hs1)
            w -= ws1;
        if(h == hs2)
            w -= ws2;

        if(w < 0) w = 0;

        h--;

        if(h == 0) {
            cout << w << endl;
            break;
        }
        
        

    }
}
