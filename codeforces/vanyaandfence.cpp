// http://codeforces.com/contest/677/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, h;
    cin >> n >> h;
    int ret = 0;
    while(n--) {
        int a;
        cin >> a;

        if(a > h) ret += 2; else ret ++;
    }

    cout << ret << endl;
}
