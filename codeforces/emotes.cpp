// https://codeforces.com/contest/1117/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long

    int N, M, K;
    cin >> N >> M >> K;

    int a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int max, smax;
    if(a[0] > a[1]) {
        smax = a[1];
        max = a[0];
    } else {
        smax = a[0];
        max = a[1];
    }

    for(int i = 2; i < N; i++) {
        if(a[i] >= max) {
            smax = max;
            max = a[i];
        } else if (a[i] > smax) {
            smax = a[i];
        }
    }

    int x = (M / (K+1)) * ((max * K) + smax);
    int y = (M % (K+1)) * max;
    cout << x + y << "\n";
}
