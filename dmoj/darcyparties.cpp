// https://dmoj.ca/problem/vpex1p2

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N];
    int tot = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];

        tot += a[i];
    }

    int should = tot / N;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] != should) {
            ans++;
        }
    }

    cout << ans << endl;

}