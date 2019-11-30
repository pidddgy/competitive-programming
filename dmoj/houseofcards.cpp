// https://dmoj.ca/problem/dmpg18b6

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int w[N];
    for(auto &x: w) cin >> x;

    sort(w, w+N);

    int cur = w[0];
    int h = 1;

    for(int i = 1; i < N; i++) {
        if(w[i] - cur >= K) {
            h++;
            cur = w[i];
        }
    }

    cout << h << endl;
}
