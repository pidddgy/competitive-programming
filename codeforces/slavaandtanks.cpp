// https://codeforces.com/contest/877/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> ans;
    vector<int> ans2;
    for(int i = 1; i <= N; i += 2) {
        ans.emplace_back(i);
    }
    for(int i = 2; i <= N; i += 2) {
        ans.emplace_back(i);
    }
    for(int i = 1; i <= N; i += 2) {
        ans.emplace_back(i);
    }

    for(int i = 2; i <= N; i += 2) {
        ans2.emplace_back(i);
    }

    for(int i = 1; i <= N; i += 2) {
        ans2.emplace_back(i);
    }

    for(int i = 2; i <= N; i += 2) {
        ans2.emplace_back(i);
    }

    if(ans.size() < ans2.size()) {
        cout << ans.size() << endl;
        for(int x: ans ) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << ans2.size() << endl;
        for(int x: ans2 ) {
            cout << x << " ";
        }
        cout << endl;
    }

}