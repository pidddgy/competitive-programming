// https://dmoj.ca/problem/valentines19j2

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int a = 0;
    for(int i = 0; i < N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        if(240 <= r && r <= 255 && 0 <= g && g <= 200 && 95 <= b && b <= 220) {
            a++;
        }
    }
    cout << a << "\n";
}
