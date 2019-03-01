// https://dmoj.ca/problem/dmpg15s3

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int AQT_IS_CUTE_AND_ADORABLE_AND_WILL_MAKE_IOI[N];
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> AQT_IS_CUTE_AND_ADORABLE_AND_WILL_MAKE_IOI[i];
        sum += AQT_IS_CUTE_AND_ADORABLE_AND_WILL_MAKE_IOI[i];
    }

    int M; cin >> M;
    pii bqt[M];
    for(int i = 0; i < M; i++) {
        pii cute;
        cin >> cute.fi >> cute.se;
        bqt[i] = {cute.fi, cute.se};
    }

    for(int i = 0; i < M; i++) {
        int ind = bqt[i].fi-1;
        if(min(AQT_IS_CUTE_AND_ADORABLE_AND_WILL_MAKE_IOI[ind], AQT_IS_CUTE_AND_ADORABLE_AND_WILL_MAKE_IOI[ind+1]) < bqt[i].se) {
            sum -= min(AQT_IS_CUTE_AND_ADORABLE_AND_WILL_MAKE_IOI[ind], AQT_IS_CUTE_AND_ADORABLE_AND_WILL_MAKE_IOI[ind+1]);
        } else {
            sum -= bqt[i].se;
        }
    }

    cout << sum << "\n";
}
