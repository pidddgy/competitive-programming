// https://codeforces.com/contest/74/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    string ignore, dir;
    cin >> ignore >> dir;

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            if(m < k) {
                m--;
            } else if(m > k) {
                m++;
            }
            m = max(m, 1);
            m = min(m, n);

            if(dir == "head") {
                k--;
            } else {
                k++;
            }

            if(k == 1) {
                dir = "tail";
            } else if(k == n) {
                dir = "head";
            }

            if(m == k) {
                cout << "Controller " << i+1 << endl;
                return 0;
            }
        } else {
            if(dir == "head") {
                k--;
            } else {
                k++;
            }

            if(k == 1) {
                dir = "tail";
            } else if(k == n) {
                dir = "head";
            }

            if(dir == "tail") {
                m = 1;
                if(k == 1) m = 2;
            } else {
                m = n;
                if(k == n) m = n-1;
            }

            if(m == k) {
                cout << "Controller " << i+1 << endl;
                return 0;
            }
        }

    }

    cout << "Stowaway" << endl;
}