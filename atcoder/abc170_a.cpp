// https://atcoder.jp/contests/abc170/tasks/abc170_a

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 5; i++) {
        int a;
        cin >> a;

        if(a==0) {
            cout << i << endl;
        }
    }   
}