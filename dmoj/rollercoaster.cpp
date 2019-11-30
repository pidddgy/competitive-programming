// https://dmoj.ca/problem/dmopc19c2p0

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N, M, H; 
    cin >> N >> M >> H;

    int ans = 0;
    while(N--) {
        int cute;
        cin >> cute;

        if(cute >= M and cute <= H) {
            ans++;
        }
    }

    cout << ans << endl;
}