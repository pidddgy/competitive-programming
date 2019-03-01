// https://dmoj.ca/problem/nccc7j2

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t = 0;
    int jelly = 0;

    
    for(int i = 0; i < 7; i++) {
        char a;
        cin >> a;
        if(a == 'J') {
            jelly += 1;
            if(i < 6)
            continue;
        }

        if(a == 'T' && jelly != 0) {
            jelly = 0;
            t++;
        } else if (i == 6 && jelly != 0) {
            jelly = 0;
            t++;
        }


    }

    cout << t << endl;
}
