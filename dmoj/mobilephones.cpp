// https://dmoj.ca/problem/ioi01p1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int bit[1030][1030];
int N;

int q(int x, int y) {
    int ans = 0;
    for(int i = x; i >= 1; i -= i & -i) {
        for(int j = y; j >= 1; j -= j & -j) {
            // cout << "aaaaaa" << endl;
            ans += bit[i][j];
        }
    }

    return ans;
}

int main() {
    for(;;) {
        int query; cin >> query;

        if(query == 0) {
            cin >> N;
        } else if(query == 1) {
            int x, y, a;
            cin >> x >> y >> a;

            x++;
            y++;

            for(int i = x; i <= N; i += i & -i) {
                for(int j = y; j <= N; j += j & -j) {
                    bit[i][j] += a;
                }
            }
        } else if(query == 2) {
            int l, b, r, t;
            cin >> l >> b >> r >> t;
            l++;
            b++;
            r++;
            t++;
            
            cout << q(r, t) - q(l-1, t) - q(r, b-1) + q(l-1, b-1) << endl;
        } else if (query == 3) break;
    }
}