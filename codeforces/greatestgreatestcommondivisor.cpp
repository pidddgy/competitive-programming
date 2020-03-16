// https://codeforces.com/problemsets/acmsguru/problem/99999/499

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    int a[n];
    int ma = 0;
    for(auto &x: a) {
        cin >> x;
        ma = max(ma, x);
    }

    int cnt[ma+123];
    for(int i = 0; i < ma+123; i++) cnt[i] = 0;

    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    for(int i = ma; i >= 1; i--) {
        int j = i;
        int k = 0;

        while(j <= ma) {
            if(cnt[j]) k++;
            if(k == 2) {
                cout << i << endl;
                return 0;
            } else j += i;
        }
    }
}