// https://codeforces.com/contest/1305/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

const int maxn = 20500;
const int maxm = 1300;

int n, m; 
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    if(n > m) {
        cout << 0 << endl;
        return 0;
    }

    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            watch(i)
            watch(j)
            ans *= abs(a[i]-a[j]) % m;
            ans %= m;
        }
    }

    cout << ans << endl;

}