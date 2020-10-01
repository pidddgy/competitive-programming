// https://dmoj.ca/problem/dmopc19c6p0

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if(a < (b+c) and b < (a+c) and c < (a+b)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}