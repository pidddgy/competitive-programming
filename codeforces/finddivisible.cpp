// http://codeforces.com/contest/1096/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++) {
        long long a, b;
        cin >> a >> b;
        cout << a << " " << a*(b/a) << endl;
    }
}
