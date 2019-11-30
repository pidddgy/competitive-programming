// https://dmoj.ca/problem/thicc17p5

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cnt[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    ll d = 0;
    int r = 0;
    ll t = 0;

    for(int l = 0; l < N; l++) {
        while(r < N && d < K) {
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
