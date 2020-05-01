// https://codeforces.com/contest/991/problem/D

#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int ans = 0;
    int prev = (a[0] == '0') + (b[0] == '0');
    for(int i = 1; i < a.size(); i++) {
        int cur = (a[i] == '0') + (b[i] == '0');
        if(cur == 0) {
            prev = 0;
            continue;
        } else if(prev == 0) {
            prev = cur;
            continue;
        } else if(prev == 1) {
            if(cur == 2) {
                ans++;
                prev = 0;
                cerr << "a adding at ind " << i << endl;
                continue;
            }
        } else if (prev == 2) {
            if(cur == 2) {
                prev = 1;
                ans++;
                cerr << "b adding at ind " << i << endl;

                continue;
            } else if(cur == 1) {
                prev = 0;
                ans++;
                cerr << "c adding at ind " << i << endl;

                continue;
            }
        }
    }

    cout << ans << endl;
}