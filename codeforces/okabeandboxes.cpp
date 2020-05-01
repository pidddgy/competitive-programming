// https://codeforces.com/contest/821/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> dq;
    int currem = 1;
    int ans = 0;
    for(int i = 1; i <= 2*n; i++) {
        string query;
        cin >> query;

        if(query == "add") {
            int x;
            cin >> x;
            
            dq.push_front(x);
        } else if(query == "remove") {
            if(dq.front() != currem) {
                sort(dq.begin(), dq.end());
                ans++;
            }
            
            dq.pop_front();
            currem++;
        }
    }

    cout << ans << endl;
}