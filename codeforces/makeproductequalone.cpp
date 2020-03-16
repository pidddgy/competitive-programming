// http://codeforces.com/contest/1206/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int nonpos = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] <= 0) nonpos++;
    }

    int neg1 = (nonpos/2)*2;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] <= 0 and neg1) {
            ans += abs(a[i]-(-1));
            neg1--;
        } else {
            ans += abs(a[i] - 1);
        }
    }

    cout << ans << endl;
}