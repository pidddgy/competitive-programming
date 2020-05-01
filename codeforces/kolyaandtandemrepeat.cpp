// https://codeforces.com/contest/443/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;

    int N = S.size();

    S = "."+S;

    int k;
    cin >> k;

    int ma = 0;
    for(int i = 1; i <= N; i++) {
        for(int n = 1; n <= 800; n++) {
            if(i+(2*n)-1 > N+k) {
                continue;
            }

            bool good = true;

            for(int j = i; j <= i+n-1; j++) {
                if(j+n > N) {
                    break;
                }

                if(S[j] != S[j+n]) good = false;
            }

            if(good) {
                ma = max(ma, 2*n);
            }
        }
    }

    cout << ma << endl;
}