// https://dmoj.ca/problem/nccc6s1  

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    double cur;
    for(int i = 0; i < N; i++) {
        double a;
        cin >> a;

        cur+=a;
    }
    cur/=N;

    cout << fixed <<setprecision(1) << cur <<endl;
}