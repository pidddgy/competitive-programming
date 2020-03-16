// https://codeforces.com/contest/1300/problem/0    

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int a[N+1];
        int sum = 0;

        for(int i = 1; i <= N; i++) { 
            cin >> a[i];
        }

        int ans = 0;
        for(int i = 1; i <= N; i++) {
            if(a[i] == 0) {
                a[i]++;
                ans++;
            }
        }

        int sum2 = 0;
        for(int i = 1; i <= N; i++) {
            sum2 += a[i];
        }

        if(sum2 == 0) {
            ans++;
        }


        cout << ans << endl;
    }
}