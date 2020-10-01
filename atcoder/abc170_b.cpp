// https://atcoder.jp/contests/abc170/tasks/abc170_b

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int X, Y;
    cin >> X >> Y;

    for(int i = 0; i <= X; i++) {
        if(2*i + 4*(X-i) == Y) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}