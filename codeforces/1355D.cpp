// https://codeforces.com/contest/1355/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    if(N > S) {
        cout << "NO" << endl;
        return 0;
    }

    if(N == 1) {
        if(S == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << S << endl;
            cout << 1 << endl;
        }
        return 0;
    }

    if(N == 2) {
        if(S <= 3) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << S/2 << " " << S-(S/2) << endl;
            cout << 1 << endl;
        }
        return 0;
    }

    // put ones on left, middle val, big val
    for(int i = 1; i <= N; i++) {
        int mid = i+2;
        int right = S-i-mid;

        int big = -1;
        if(!(N-i-1)) continue;
        if(right / (N-i-1) > mid) {
            big = right / (N-i-1);
        }

        if(big != -1) {
            int ans[N+1];
            int rem = S;
            for(int j = 1; j <= i; j++) {
                ans[j] = 1;
                rem--;
            }
            ans[i+1] = mid;
            rem -= mid;

            for(int j = i+2; j <= N; j++) {
                ans[j] = big;
                rem -= big;
            }
            ans[N] += rem;

            cout << "YES" << endl;
            for(int i = 1; i <= N; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;

            cout << mid-1 << endl;
            return 0;
        }
    }

    // consider no big val
    int last = S-(N-1);
    if(last > N) {
        cout << "YES" << endl;
        for(int i = 1; i <= N-1; i++) {
            cout << 1 << " ";
        }
        cout << last << endl;
        cout << last-1 << endl;

        return 0;
    }


    // consider no ones
    if(2*N <= S) {
        int rem = S;
        cout << "YES" << endl;
        for(int i = 1; i <= N-1; i++) {
            cout << 2 << " ";
            rem -= 2;
        }
        cout << rem << endl;
        cout << 1 << endl;

        return 0;
    }

    cout << "NO" << endl;
}