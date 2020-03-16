// https://codeforces.com/contest/1321/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int r[N+1];
    int b[N+1];

    for(int i = 1; i <= N; i++) {
        cin >> r[i];
    }

    for(int i = 1; i <= N; i++) {
        cin >> b[i];
    }


    int rbeats = 0;
    int bbeats = 0;
    for(int i = 1; i <= N; i++) {
        if(b[i] and !r[i]) {
            bbeats++;
        } else if(r[i] and !b[i]) {
            rbeats++;
        }
    }
    
    if(rbeats == 0) {
        cout << -1 << endl;
        return 0;
    }
    // how much do we have to multiply rbeats by to make it beat bbeats?
    int ans = ceil(((double)bbeats+1.0) / (double)rbeats);

    cout << ans << endl;
}