// https://atcoder.jp/contests/abc142/tasks/abc142_c

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;

int ans[maxn];
int N;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        ans[a] = i;
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
