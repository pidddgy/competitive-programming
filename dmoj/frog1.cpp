// https://dmoj.ca/problem/dpb

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    int d[N];
    for(int i = 0; i < N; i++) d[i] = 2147483647;
    d[0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= 2 && i+j < N; j++) {
            int h = abs(a[i] - a[i+j]);
            if(h + d[i] < d[i+j]) {
                d[i+j] = h+d[i];
            }
        }
    }

    cout << d[N-1] << endl;
}

