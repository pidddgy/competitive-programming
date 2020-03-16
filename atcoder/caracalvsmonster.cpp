// https://atcoder.jp/contests/abc153/tasks/abc153_d

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {

    
    #define int long long
    int H;
    cin >> H;

    int curnum = 1;
    int ans = 0;
    while(H != 1) {
        H /= 2;
        ans += curnum;
        curnum *= 2;

        // watch(H)
        // watch(curnum)
    }

    cout << ans+curnum << endl;
    
}