// http://codeforces.com/contest/1173/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;

    if(x==y) {
        if(z == 0)
            cout << 0 << endl;
        else 
            cout << "?" << endl;
        return 0;
    }

    if(x > y) {
        y += z;
        if(x > y) {
            cout << "+" << endl;
        } else {
            cout << "?" << endl;
        }
    } else if (y > x) {
        x += z;
        if(y > x) {
            cout << "-" << endl;
        } else {
            cout << "?" << endl;
        }
    }


}