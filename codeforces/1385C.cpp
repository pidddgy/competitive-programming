// https://codeforces.com/contest/1385/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

bool ok(deque<int> arr) {
    vector<int> shit;
    shit.emplace_back(-100);

    // cerr << "trying with:" << endl;
    // for(int x: arr) {
    //     cerr << x << " ";
    // }
    // cerr << endl;

    while(arr.size()) {
        if(min(arr.front(), arr.back()) < shit.back()) {
            return false;
        }

        if(arr.front() < arr.back()) {
            shit.emplace_back(arr.front());
            arr.pop_front();
        } else {
            shit.emplace_back(arr.back());
            arr.pop_back();
        }
    }

    return true;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int l = 0;
        int r = n;
        int lgood = -1;

        while(l <= r) {
            int m = (l+r)/2;

            deque<int> dq;

            for(int i = m+1; i <= n; i++) {
                dq.emplace_back(a[i]);
            }

            if(ok(dq)) {
                lgood = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }

        cout << lgood << endl;
    }
}