// https://codeforces.com/contest/1385/problem/%20B

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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a;

        for(int i = 1; i <= n*2; i++) {
            int x;
            cin >> x;

            a.emplace_back(x);
        }

        vector<int> p1, p2;

        for(int x: a) {
            if(find(p1.begin(), p1.end(), x) != p1.end()) {
                p2.emplace_back(x);
            } else {
                p1.emplace_back(x);
            }
        }

        for(int x: p1) {
            cout << x << " ";
        }
        cout << endl;
    }
}
