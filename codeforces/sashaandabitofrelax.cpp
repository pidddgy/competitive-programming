// https://codeforces.com/contest/1109/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define cerr if(false) cerr

const int maxn = 300500;
const int maxa = 1058576;

int a[maxn];
int pxor[maxn];
int cnt[2][maxa];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int pxor[n+1];
    pxor[0] = 0;

    for(int i = 1; i <= n; i++) {
        pxor[i] = a[i]^pxor[i-1];
        cerr << pxor[i] << " ";
    }
    cerr << endl;

    int ans = 0;
    cnt[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        cerr << "adding " << cnt[i%2][pxor[i]] << " at " << i << endl;
        ans += cnt[i%2][pxor[i]];
        cnt[i%2][pxor[i]]++;
    }

    cout << ans << endl;
}