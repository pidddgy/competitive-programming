// https://codeforces.com/contest/1330/problem/0

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, x;
        cin >> n >> x;

        unordered_map<int, bool> have;
        for(int i = 1; i <= n; i++) {
            int _;
            cin >> _;

            have[_] = true;
        }

        for(int i = 1; i <= 2000; i++) {
            if(!have[i] and x == 0) {
                cout << i-1 << endl;
                break;
            } else if(!have[i]) {
                x--;
            }
        }
    }
}
