// https://codeforces.com/contest/1141/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    int res = 0;
    int cur = 0;


    for(auto x: a) {
        if(x == 1) {
            cur++;
            res = max(res, cur);
        } else {
            cur = 0;
        }
    }

    for(auto x: a) {
        if(x == 1) {
            cur++;
            res = max(res, cur);
        } else {
            cur = 0;
        }
    }

    cout << res<<endl;
}
