// https://atcoder.jp/contests/abc125/tasks/abc125_b

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int v[N];
    int c[N];

    for(auto &x: v) cin >> x;
    for(auto &x: c) cin >> x;

    int X=0, Y=0;
    for(int i = 0; i < N; i++) {
        if(v[i] > c[i]) {
            X += v[i];
            Y += c[i];
        }
    }

    cout << X-Y << endl;
}
