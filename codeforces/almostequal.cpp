// http://codeforces.com/contest/1206/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    if(N%2 ==0) {
        cout << "NO" << endl;
        return 0;
    } else cout << "YES" << endl;

    int ans[(N*2)+5];

    int incr = 3;

    ans[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(incr == 1) {
            ans[i] = ans[i-1]+1;
            incr = 3;
        } else {
            ans[i] = ans[i-1]+3;
            incr = 1;
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    for(int i = 1; i <= N; i++) {
        if(i % 2 == 0)
            cout << ans[i]-1 << " ";
        else cout << ans[i]+1 << " ";
    }
    cout << endl;
}