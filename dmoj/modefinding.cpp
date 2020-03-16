// https://dmoj.ca/problem/dmopc19c3p1

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    

    map<int, int> cnt;
    for(int i = 0; i < N; i++) {
        cnt[a[i]]++;
    }

    int ma = 0;
    for(pii x: cnt) {
        ma = max(ma, x.se);
    }

    vector<int> ans;

    for(pii x: cnt) {
        if(x.se == ma) {
            ans.emplace_back(x.fi);
        }
    }

    sort(ans.begin(), ans.end());

    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}