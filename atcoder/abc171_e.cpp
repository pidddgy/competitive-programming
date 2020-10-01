// https://atcoder.jp/contests/abc171/tasks/abc171_e

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;

int a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int t = 0;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        t ^= a[i];
    }

    for(int i = 1; i <= N; i++) {
        cout << (t^a[i]) << " ";
    }
    cout << endl;
}
