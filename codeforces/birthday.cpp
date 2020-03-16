// http://codeforces.com/problemset/problem/1131/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    sort(a, a+N);

    for(int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


}
