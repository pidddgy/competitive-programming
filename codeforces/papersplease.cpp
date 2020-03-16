// https://atcoder.jp/contests/abc155/tasks/abc155_b

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    string ans = "APPROVED";

    for(int i = 1; i <= N; i++) {
        if(a[i] % 2 == 0) {
            if(!((a[i] % 3 == 0) || (a[i]%5 == 0))) {
                ans = "DENIED";
            }
        }
    }

    cout << ans << endl;
}