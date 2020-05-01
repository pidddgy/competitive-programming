// https://codeforces.com/contest/959/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    if(N < 6) {
        cout << -1 << endl;
    } else {
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 3 << endl;
        cout << 1 << " " << 6 << endl;
        cout << 2 << " " << 4 << endl;
        cout << 2 << " " << 5 << endl;

        for(int i = 7; i <= N; i++) {
            cout << 1 << " " << i << endl;
        }
    }

    for(int i = 1; i <= N-1; i++) {
        cout << i << " " << i+1 << endl;
    }


}