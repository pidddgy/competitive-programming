// https://codeforces.com/problemsets/acmsguru/problem/99999/123

#include <bits/stdc++.h>
using namespace std;
int main() {
    int f[60];
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i < 50; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    int tot = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        tot += f[i];
    }
    cout << tot << endl;
}