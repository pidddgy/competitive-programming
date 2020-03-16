// https://codeforces.com/contest/1262/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    #define endl '\n'
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        int a[N+1];
        for(int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        vector<int> ans;
        set<int> used;
        int ma = 0;
        int leftover = 1;
        bool dont = false;

        for(int i = 1; i <= N; i++) {
            if(dont) break;
            if(a[i] > a[i-1] or i == 1) {
                ans.emplace_back(a[i]);
                ma = a[i];
                used.emplace(a[i]);
            } else {
                while(used.find(leftover) != used.end() and leftover < N) {
                    leftover++;
                }

                ans.emplace_back(leftover);
                used.emplace(leftover);

                if(leftover > a[i]) {
                    cout << -1 << endl;
                    dont = true;
                }
            }
        }

        if(!dont) {
            for(int x: ans) {
                cout << x << " ";
            }
            cout << endl;
        }

    }
}