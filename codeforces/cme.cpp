// https://codeforces.com/contest/1241/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long

    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        if(n < 4) {
            cout << 4-n << endl;
        } else {
            cout << n%2 << endl;
        }
    }
}