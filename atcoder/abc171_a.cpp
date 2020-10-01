// https://atcoder.jp/contests/abc171/tasks/abc171_a

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    char x;
    cin >> x;

    if(isupper(x)) {
        cout << "A" << endl;
    } else {
        cout << "a" << endl;
    }
}
