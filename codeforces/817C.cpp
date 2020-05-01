// https://codeforces.com/contest/817/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr

int sum(int n) {
    int ans = 0;
    while(n) {
        ans += n%10;
        n /= 10;
    }

    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    // for(int i = 1; i <= 1e5; i++) {
    //     cout << i << " - " << i-sum(i) << endl;
    // }

    int l = 1;
    int r = n;
    int ans = 0;

    while(l <= r) {
        int m = (l+r)/2;
        watch(m)
        if(m-sum(m) >= s) {
            ans = (n-m)+1;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    cout << ans << endl;
}