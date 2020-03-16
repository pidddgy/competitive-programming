// https://atcoder.jp/contests/abc153/tasks/abc153_b

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int H, N;
    cin >> H >> N;

    int sum = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        sum += a;
    }

    if(sum >= H) {
        cout << "Yes" << endl; 
    } else {
        cout << "No" << endl;
    }
}