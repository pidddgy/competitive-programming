// https://atcoder.jp/contests/abc171/tasks/abc171_d

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 100500;

map<int, int> cnt;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int sum = 0;
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        sum += a;
        cnt[a]++;
    }

    int Q;
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int b, c;
        cin >> b >> c;

        sum -= cnt[b]*b;
        sum += cnt[b]*c;

        cnt[c] += cnt[b];
        cnt[b] = 0;

        cout << sum << endl;
    }
}
