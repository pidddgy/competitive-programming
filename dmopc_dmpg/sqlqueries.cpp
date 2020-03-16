// https://dmoj.ca/problem/dmopc18c6p0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int a[4];
    cin >> a[1] >> a[2] >> a[3];


    if( (a[a[a[1] ]] == 1 || a[a[1]] == 1 || a[1] == 1) && a[1] != 0) {
        cout << "NO" << endl;
        return 0;
    }

    if( (a[a[a[2] ]] == 2 || a[a[2]] == 2 || a[2] == 2) && a[2] != 0) {
        cout << "NO" << endl;
        return 0;
    }

    if( (a[a[a[3] ]] == 3 || a[a[3]] == 3 || a[3] == 3) && a[3] != 0) {
        cout << "NO" << endl;
        return 0;
    }


    cout << "YES" << endl;
}

