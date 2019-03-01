// https://codeforces.com/problemset/problem/670/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    long long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        if(k - i > 0) {
            k -= i;
        } else {
            cout << a[k-1] << endl;
            break;
        }
    }
}
