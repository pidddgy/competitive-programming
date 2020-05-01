// https://codeforces.com/contest/1327/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    string s;

    for(int i = 1; i <= n-1; i++) {
        for(int j = 1; j <= m-1; j++) {
            if(i % 2 == 1) {
                s += "R";
                ans++;
            } else {
                s += "L";
                ans++;
            }
        }
        s += "D";
        ans++;
    }

    for(int i = 1; i <= m-1; i++) {
        if(n % 2 == 0) {
            s += "L";
            ans++;
        } else {
            s += "R";
            ans++;
        }
    }

    // s += " ";
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= m-1; j++) {
            if(i % 2 == 1) {
                s += "L";
                ans++;
            } else {
                s += "R";
                ans++;
            }
        }

        if(i != 1) {
            s += "U";
            ans++;
        }
    }

    cout << ans << endl;
    cout << s << endl;
}