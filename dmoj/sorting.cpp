// https://dmoj.ca/problem/dmopc18c1p0

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a <= b && b <= c) {
        cout << "Good job!\n";
    } else {
        cout << "Try again!\n";
    }
}
