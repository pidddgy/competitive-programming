// http://codeforces.com/contest/1178/problem/F1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int n = 5;
int ans = 0;

void f(string a, int c) {
    watch(a)
    if(a == "01234567") {
        ans++;
        return;
    } else {
        for(int i = c; i <= n; i++) {
            char thing = a[i];
            for(int j = i; j <= n; j++) {
                if(a[j] == thing) {
                    string newa = a;
                    for(int k = i; k <= j; k++) {
                        newa[k] = c+'0';
                    }
                    f(newa, c+1);
                } else break;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    string init = "00000000";
                //  "0123456"
    f(init, 1);

    cout << ans << endl;
}