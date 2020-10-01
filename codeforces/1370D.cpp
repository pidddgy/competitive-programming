// https://codeforces.com/contest/1370/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;

int n, k;
int a[maxn];

bool f(int x) {

    int odd = 0;
    for(int i = 1; i <= n; i++) {
        if(odd%2==0) {
            if(a[i] <= x) {
                odd++;
            }
        } else {
            odd++;
        }
    }

    int even = 0;
    for(int i = 1; i <= n; i++) {
        if(even%2==1) {
            if(a[i] <= x) {
                even++;
            }
        } else {
            even++;
        }
    }

    return (odd >= k) or (even >= k);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1;
    int r = 1e9+500;

    int ans = -1;
    while(l <= r) {
        int m = (l+r)/2;

        if(f(m)) {
            ans = m;
            r = m-1; 
        } else {
            l = m+1;
        }
    }

    cout << ans << endl;
}