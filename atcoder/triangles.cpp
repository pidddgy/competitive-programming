// https://atcoder.jp/contests/abc143/tasks/abc143_d

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'

using namespace std;

bool valid(int a, int b, int c) {
    return ((a < b+c) and (b < c+a) and (c < b+a));
}

int main() {
    #define int long long
    int N;
    cin >> N;

    int L[N];
    int s[N];

    for(int i = 0; i < N; i++) {
        cin >> L[i];
        s[i] = L[i];
    }

    sort(s, s+N);

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
        
            int l = j+1;
            int r = N-1;
            int ma = -1;

            while(l <= r) {
                int m = (l+r)/2;
                // watch(m)

                if(valid(s[i], s[j], s[m])) {
                    l = m+1;
                    ma = m;
                    // cout << "Hi" << endl;
                } else {
                    r = m-1;
                }
            }

            if(ma == -1) continue;
            else ans += ma-j;

            // cout << endl;
        }
    }


    cout << ans << endl;


    
}