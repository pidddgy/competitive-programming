// https://dmoj.ca/problem/coci17c2p3

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a[N+1];
    a[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int pref[N+1];
    pref[0] = 0;
    for(int i = 1; i <= N; i++) {
        pref[i] = 0;
        pref[i] += pref[i-1];
        if(a[i] == i) pref[i]++;
    }

    vector<int> center[N*2 + 500];

    for(int i = 1; i <= N; i++) {
        center[a[i] + i].emplace_back(abs((i*2)-(a[i]+i)));
    }

    int best = INT_MIN;
    int bestl = 0;
    int bestr = 0;

    for(int i = 2; i <= N*2; i++) {
        sort(center[i].begin(), center[i].end());

        int add = 0;

        for(int r: center[i]) {
            add++;
            int L = (i-r) / 2;
            int R = (i+r) / 2;

            assert((i+r) % 2 == 0);

            int rem = pref[R] - pref[L-1];

            if((add-rem) >= best) {
                // cout << bestl << " " << bestr << endl;
                // cout << "gains " << add << ", loses " << rem << endl;
                best = add-rem;
                bestl = a[L];
                bestr = a[R];
            }
        }
    }

    cout << bestl << " " << bestr << endl;
}