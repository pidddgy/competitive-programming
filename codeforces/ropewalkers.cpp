// http://codeforces.com/contest/1185/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long
    int a[4];
    int d;
    int ans = 0;

    cin >> a[1] >> a[2] >> a[3] >> d;

    sort(a+1, a+4);

    if(abs(a[2]-a[3]) < d) ans += abs(a[3]-(a[2]+d));
    if(abs(a[2]-a[1]) < d) ans += abs(a[1]-(a[2]-d));

    cout << ans << endl;
    

}