// https://codeforces.com/contest/1355/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int a1, K;
        cin >> a1 >> K;

        vector<int> a;
        a.emplace_back(a1);

        for(int i = 2; i <= K; i++) {
            string x = to_string(a[a.size()-1]);
            int mi = *min_element(x.begin(), x.end())-'0';
            int ma = *max_element(x.begin(), x.end())-'0';

            if(mi*ma == 0) {
                break;
            }

            a.push_back(a[a.size()-1]+mi*ma);
        }

        cout << a[a.size()-1] << endl;
    }
}
