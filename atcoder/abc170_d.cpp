// https://atcoder.jp/contests/abc170/tasks/abc170_d

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;
const int maxa_i = 1000500;

int a[maxn];
bool bad[maxa_i];
map<int, int> cnt;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        cnt[a[i]]++;

        if(cnt[a[i]] == 2) {
            bad[a[i]] = true;
            for(int j = a[i]; j <= 1e6; j += a[i]) {
                bad[j] = true;
            }
        }
    }

    sort(a+1, a+N+1);

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(!bad[a[i]]) {
            ans++;
            
            for(int j = a[i]; j <= 1e6; j += a[i]) {
                bad[j] = true;
            }
        }
    }

    cout << ans << endl;
}

