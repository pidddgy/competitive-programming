// https://codeforces.com/contest/1163/problem/B2

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    map<int, int> cnt1, cnt2;
    int ma = 0;

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        cnt2[cnt1[x]]--;
        cnt1[x]++;
        cnt2[cnt1[x]]++;

        ma = max(ma, cnt1[x]);

        bool ok = false;
        if(cnt2[1] == i) {
            ok = true;
        }

        if(cnt2[i] == 1) {
            ok = true;
        }

        if(cnt2[1] == 1 and cnt2[ma]*ma == i-1) {
            ok = true;
        }

        if(cnt2[ma-1]*(ma-1) == i-ma and cnt2[ma] == 1) {
            ok = true;
        }

        if(ok) ans = i;
    }

    cout << ans << endl;
}