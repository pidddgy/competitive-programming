// https://codeforces.com/contest/1249/problem/C2

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        int ans = 0;
        int raise = 0;

        while(ans < n) {
            ans += powl(3, raise);
            raise++;
        }

        for(int i = raise; i >= 0; i--) {
            if(ans - powl(3, i) >= n) {
                ans -= powl(3, i);
            }
        }

        cout << ans << endl;



    }
}