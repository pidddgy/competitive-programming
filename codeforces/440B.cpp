// https://codeforces.com/contest/440/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
signed main() {
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

    int ea = sum/n;

    int cost = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > ea) {
            a[i+1] += a[i]-ea;
            cost += a[i]-ea;
        } else if(a[i] < ea) {
            a[i+1] -= ea-a[i];
            cost += ea-a[i];
        }
        a[i] = ea;
    }

    cout << cost << endl;
}