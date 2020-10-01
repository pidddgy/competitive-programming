// https://codeforces.com/contest/1355/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
const int maxn = 2000000;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    for(int i = A; i <= B; i++) {
        a[i+B]++;
        a[i+C+1]--;
    }    

    for(int i = 1; i < maxn; i++) {
        a[i] += a[i-1];
    }

    for(int i = 1; i < maxn; i++) {
        a[i] += a[i-1];
    }

    int ans = 0;
    for(int i = C; i <= D; i++) {
        ans += a[maxn-1] - a[i];
    }
    
    cout << ans << endl;
}