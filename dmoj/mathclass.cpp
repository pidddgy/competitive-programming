// https://dmoj.ca/problem/dmopc19c4p4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define int long long
using namespace std;

long double euclideanDistance(int x, int y, int a, int b) {
    return sqrt((abs(x-a))*(abs(x-a)) + (abs(y-b))*(abs(y-b)));
}

signed main() {
    int N;
    cin >> N;

    int Ax, Ay;
    cin >> Ax >> Ay;

    int Bx, By;
    cin >> Bx >> By;

    int x, y;

    cin >> x >> y;
    watch(euclideanDistance(x, y, Ax, Ay))
    watch(euclideanDistance(x, y, Bx, By))
    if(euclideanDistance(x, y, Ax, Ay) == euclideanDistance(x, y, Bx, By)) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
}