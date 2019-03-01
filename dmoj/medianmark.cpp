// https://dmoj.ca/problem/dmopc14c1p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a+N);

    if(N % 2 == 0) {
        long double thing = (a[ N/2 ] + a[(N/2)-1]) / 2.0;
        cout << round(thing) << endl;
    } else {
        cout << a[N / 2] << endl;
    }
}
