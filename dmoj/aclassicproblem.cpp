// https://dmoj.ca/problem/dmopc15c6p5

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int a[N];
    for(auto &x: a) cin >> x;

    int ans = 0;
    int l = 0;
    int r = 0;
    int ma = a[0];
    int mi = a[0];

    while(r < N) {
        while(ma-mi <= K) {
            r++;
            ma = max(a[r], ma);
            mi = min(a[r], mi);
        }
    }

}