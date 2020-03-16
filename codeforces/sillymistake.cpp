// http://codeforces.com/contest/1253/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    set<int> S;
    set<int> seen;

    vector<int> ans;
    int i = 1;
    int cur = 1;
    while(i <= N) {
        if(a[i] > 0) {
            if(seen.find(a[i]) != seen.end()) {
                cout << -1 << endl;
                return 0;
            }
            seen.emplace(a[i]);
            S.emplace(a[i]);
        } else if(a[i] < 0) {
            if(S.find(a[i]*-1) == S.end()) {
                cout << -1 << endl;
                return 0;
            }
            S.erase(a[i]*-1);
        }

        if(S.size() == 0) {
            ans.emplace_back(cur);
            cur = 0;
            seen = set<int>();
        }

        i++;
        cur++;
    }

    if(S.size()) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}