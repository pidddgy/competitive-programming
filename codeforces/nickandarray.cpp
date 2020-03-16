// https://codeforces.com/contest/1180/problem/B

#include <bits/stdc++.h>
using namespace std;

int flip(int n) {
    return -n-1;
}
int main() {
    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    int ma = 0;
    int maiind = 0;
    for(int i = 0; i < N; i++) {
        a[i] = max(a[i], flip(a[i]));
        if(a[i] > ma) {
            ma = a[i];
            maiind = i;
        }
    }

    for(int i = 0; i < N; i++) {
        if(N%2==1 && i == maiind) {
            cout << a[i] << " ";
        } else {
            cout << flip(a[i]) << " ";
        }
    }
    cout << endl;


}