// https://codeforces.com/contest/1354/problem/C1

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define PI 3.14159265
#define ld long double

ld f(int n) {
    return sin(n*PI/180.0);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
    int T;
    cin >> T;
    // cout << f(30) << endl;
    while(T--) {
        int n;
        cin >> n;

        ld sides = 2*n;

        watch(sides)
        ld thing = 180.0/sides;
        watch(thing)
        watch(f(thing))
        ld radius = 1/(2*f(thing));

        cout << (2*radius)*(2*radius) << endl;
    }
}