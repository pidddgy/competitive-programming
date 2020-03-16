// http://codeforces.com/contest/1187/problem/0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++) {
        int n, s, t;
        cin >> n >> s >> t;

        int intersect = (s+t) - n;

        int ss = (s-intersect)+1;
        int tt = (t-intersect)+1;
        // int l = min(s, t) - diff;
        // int r = s+t;

        cout << max(ss, tt) << endl;
    }
}