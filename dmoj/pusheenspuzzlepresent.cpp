// https://dmoj.ca/problem/nccc6s2

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int wrong = 0;
    for(int i = 1; i <= N*N; i++) {
        int a;
        cin >> a;

        if(a != i) {
            wrong++;
        }
    }

    int b = sqrt(wrong);
    if(b*b==wrong) {
        cout << sqrt(wrong) << endl;
    } else 
        cout << sqrt(wrong+1) << endl;
}
