// https://codeforces.com/contest/1327/proklem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int T;
    cin >> T;

    while(T--) {
        int n, k;
        cin >> n >> k;

        if((n % 2 == k % 2) and k*k <= n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}