// https://codeforces.com/contest/1343/problem/0

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int cur = 2;
        int sum = 1;

        for(;;) {
            sum += cur;
            cur *= 2;

            if(n % sum == 0) {
                cout << n/sum << endl;
                break;
            }
        }
    }
}