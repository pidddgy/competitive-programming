// http://codeforces.com/blog/entry/73563

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int a[N];
        for(int i = 0; i < N; i++) {
            cin >> a[i];
        }

        int best = 0;
        for(int i = 0; i < N; i++) {
            if(a[i] >= i) {
                best = i;
            } else break;
        }

        int best2 = 0;
        for(int i = N-1; i >= 0; i--) {
            if(a[i] >= N-i-1) {
                best2 = i;
            } else break;
        }

        if(best2 <= best) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}