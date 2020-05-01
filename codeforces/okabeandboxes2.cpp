// https://codeforces.com/contest/821/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
// #define cerr if(false) cerr
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    stack<int> S;
    int cur = 1;
    for(int i = 1; i <= 2*n; i++) {
        string query;
        cin >> query;

        if(query == "add") {
            int x;
            cin >> x;

            S.push(x);
        } else if(query == "remove") {
            if(!S.empty()) {
                if(S.top() == cur) {
                    S.pop();
                } else {
                    ans++;
                    S = stack<int>();
                }
            }
            cur++;
        }
    }

    cout << ans << endl;
}