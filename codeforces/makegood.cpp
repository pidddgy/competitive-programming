// https://codeforces.com/contest/1270/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int sum = 0;
        int x = 0;

        int first;
        cin >> first;

        sum = first;
        x = sum;


        for(int i = 1; i <= n-1; i++) {
            int _;
            cin >> _;

            sum += _;
            x ^= _;
        }

        cout << 2 << endl;
        cout << x << " " << sum+x << endl;
    }
}