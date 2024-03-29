// https://dmoj.ca/problem/acc3p1

#include <bits/stdc++.h>
using namespace std;
long long cnt[1000005];
int main() {
    #define int long long
    int N, K;
    cin >> N >> K;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    int d = 0;
    int r = 0;
    int t = 0;

    for(int l = 0; l < N; l++) {
        while(d < K && r < N) {
            if(cnt[a[r]] == 0) d++;
            cnt[a[r]]++;
            r++;
        }

        if(d < K) break;

        t += N-r+1;
        cnt[a[l]]--;
        if(cnt[a[l]] == 0) d--;

    }

    cout << t << endl;
}
