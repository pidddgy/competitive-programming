// https://atcoder.jp/contests/arc079/tasks/arc079_b

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    for(int n = 10; n <= 10; n++) {
        // bigs == number of big numbers
        for(int bigs = 1; bigs <= 1; bigs++) {
            int sval = n-1-(bigs*k);
            int bval = (n-1)+abs(k*(bigs-1-n));
            watch(bval)
            watch(sval)

            if(sval >= 1 and bval >= 1) {
                watch(bigs)
                watch(k*abs(bigs-1-n))
                watch(bigs-1-n)
                for(int i = 1; i <= bigs; i++) {
                    cout << bval << " ";
                }
                for(int i = 1; i <= n-bigs; i++) {
                    cout << sval << " ";
                }
                cout << endl;
                return 0;
            }

        }
    }
}
