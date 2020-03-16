// https://atcoder.jp/contests/abc153/tasks/abc153_a

#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, N;
    cin >> H >> N;

    int att = 0;
    int ans = 0;
    while(att < H) {
        att += N;
        ans++;
    }

    cout << ans << endl;
}