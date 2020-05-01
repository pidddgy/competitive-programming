// https://codeforces.com/contest/1082/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
const int maxn = 1e5+500;

int cnt[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string S;
    cin >> S;

    S = "."+S;

    int runs = 0;
    for(int i = 1; i <= N; i++) {
        if(S[i] == 'G') {
            cnt[i]++;
            cnt[i] += cnt[i-1];
            if(cnt[i] == 1) runs++;
        }
    }

    int ma = 0;
    for(int i = N; i >= 1; i--) {
        ma = max(ma, cnt[i]);

        if(cnt[i] == 0) {
            ma = 0;
        }

        cnt[i] = ma;
    }

    for(int i = 1; i <= N; i++) {
        cerr << cnt[i] << " ";
    }
    cerr << endl;

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(cnt[i] == 0 and i != 1 and i != N) {
            if(runs > 2) {
                ans = max(ans, cnt[i-1] + cnt[i+1]+1);
            } else if(runs > 1 and ((cnt[i-1] == 0) || (cnt[i+1] == 0))){
                ans = max(ans, cnt[i-1] + cnt[i+1]+1);
            } else {
                ans = max(ans, cnt[i-1] + cnt[i+1]);
            }
        } else {
            ans = max(ans, cnt[i]);
        }
    }

    cout << ans << endl;
}