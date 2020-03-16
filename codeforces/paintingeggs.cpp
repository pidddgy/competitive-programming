// https://codeforces.com/contest/282/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int diff = 0;
    for(int i = 1; i <= n; i++) {
        int a, g;
        cin >> a >> g;

        if(diff+ a <= 500) {
            diff += a;
            cout << "A";
        } else {
            diff -= g;
            cout << "G";
        }
    }
    cout << endl;
}