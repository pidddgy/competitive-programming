// http://codeforces.com/contest/1204/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int unsigned long long

    int n, l, r;
    cin >> n >> l >> r;

    int ma = 0;
    int mi = 0;

    for(int i = 0; i < n; i++) {
        int a = pow(2, min(r-1, i));
        //watch(a)

        ma += a;
    }

    for(int i = 1; i <= l-1; i++) {
        mi += pow(2, i);
    }

    for(int i = 1; i <= n-(l-1); i++) {
        mi++;
    }

    cout << mi << " " << ma << endl;


}