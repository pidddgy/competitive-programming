// https://dmoj.ca/problem/ccc18j3

#include <bits/stdc++.h>
using namespace std;
int main() {
    int aqt[5];
    aqt[0] = 0;
    for(int i = 1; i < 5; i++) {
        cin >> aqt[i];
    }
    int a = aqt[0];
    int b = aqt[1];
    int c = aqt[2];
    int d = aqt[3];
    int e = aqt[4];
    // Line 1
    cout << "0 " << a+b << " " << a+b+c << a+b+c+d << " " << a+b+c+d+e << endl;
    cout << a << " 0 " << b << " " << b+c << " " << b+c+d << endl;
    cout << a+b << " " << b << " 0 " << c << " " << " " << c+d
}