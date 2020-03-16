// https://atcoder.jp/contests/abc143/tasks/abc143_b

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int d[N];
    for(auto &x: d) cin >> x;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            ans += d[i] * d[j];
        }
    }
    cout << ans << endl;

}