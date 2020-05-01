// https://codeforces.com/contest/1328/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    #define watch(x) cout << (#x) << " is " << (x) << endl;
    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a%b == 0) {
            cout << 0 << endl;
            continue;
        }
        int c = a/b;

        // int down = b*c;
        int up = b*(c+1);

        // watch(down)
        // watch(up)

        cout << abs(up-a) << endl;
    }
}