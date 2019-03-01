// https://dmoj.ca/problem/ccc10j4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(;;) {
        int n;
        cin >> n;
        if(n == 0) break;

        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }

        int p[n-1];
        for(int i = 0; i < n-1; i++) {
            p[i] = a[i+1] - a[i];
        }

        for(int i = 0; i < n-1; i++) {

            bool good = true;
            for(int j = i+1, k = 0; j < n-1; j++, k++) {
                if(k > i) k = 0;

                if(p[j] != p[k]) {
                    good = false;
                    break;
                }
            }
            if(good) {
                cout << i+1 << endl;
                break;
            }
        }
    }
}
