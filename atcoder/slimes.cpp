// https://atcoder.jp/contests/abc143/tasks/abc143_c

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;

    int mode = S[0];

    int ans = 1;
    for(int i = 1; i < N; i++) {
        if(S[i] != mode) {
            mode = S[i];
            ans++;
            //watch(ans);
        }
    }


    cout << ans << endl;
}