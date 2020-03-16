// http://codeforces.com/contest/1165/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    sort(a, a+N);

    int ma = 0;
    for(int i = 0; i < N; i++) {
        
        // watch(a[i])
        // watch(ma)
        if(a[i] >= ma+1) {
            ma++;
        }
    }

    cout << ma << endl;
}
