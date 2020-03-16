// https://dmoj.ca/problem/wac3p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, D, P;
    cin >> T >> D >> P;

    int met = 0;

    if(T < -40) {
        met++;
    }

    if(D >= 15) {
        met++;
    }

    if(P > 50) {
        met++;
    }

    if(met >= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}