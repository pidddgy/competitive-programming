// https://codeforces.com/contest/559/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
int sq(int n) {return n*n;};
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a[8];
    for(int i = 1; i <= 6; i++) {
        cin >> a[i];
    }    

    cout << sq(a[1]+a[2]+a[3]) - sq(a[1]) - sq(a[3]) - sq(a[5]) << endl;
}