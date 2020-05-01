// https://codeforces.com/contest/609/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define watch(x) cerr << (#x) << " is " << (x) << endl;
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a+1, a+n+1, greater<int>());

    int all = sum/n;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i <= sum%n) {
            ans += abs(a[i]-(all+1));
        } else {
            ans += abs(a[i]-all);
        }
    }

    cout << ans/2 << endl;
}