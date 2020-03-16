// https://codeforces.com/contest/1070/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long

    int n, m;
    cin >> n >> m;

    int a[n+1];

    for(int i = 1; i <= n; i++) cin >> a[i];

    a[0] = 0;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int use = max((a[i-1] + m-1)/m, (a[i]+a[i-1])/m);

        ans += use;

        a[i] = max(0LL, a[i-1]+a[i] - (use*m));
    }

    if(a[n]) ans++;



    cout << ans << endl;



}