// https://codeforces.com/contest/1307/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        int n, x;
        cin >> n >> x;

        int ma = 0;
        unordered_map<int, bool> have;

        for(int i = 1; i <= n; i++) {
            int b;
            cin >> b;

            have[b] = true;
            ma = max(ma, b);
        }

        if(have[x]) {
            cout << 1 << endl;
        } else {
            cout << max(2, (int)ceil((double)x/(double)ma)) << endl;
        }
    }
}