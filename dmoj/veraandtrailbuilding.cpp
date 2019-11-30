// https://dmoj.ca/problem/cco17p1

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    int K;
    cin >> K;

    int tot = 0;
    int prev = 1;
    vector<int> a;

    while(tot < K) {
        while( (prev+1)*(prev+2)/2 + tot <= K) {
            prev++;
        }

        tot += prev*(prev+1)/2;
        a.emplace_back(prev);
        prev = 1;
    }

    vector<pii> ans;

    int cur = 1;
    for(int x: a) {
        int b = cur;
        for(int i = 0; i < x; i++) {
            ans.emplace_back(cur, cur+1);
            cur++;
        }
        ans.emplace_back(cur, b);
        ans.emplace_back(1, cur);
        cur++;
    }

    cout << cur-1 << " " << ans.size() << endl;
    for(auto x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}
