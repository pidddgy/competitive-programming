// https://codeforces.com/problemsets/acmsguru/problem/99999/102

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else {
        return gcd(b, a%b);
    }

}
int main() {
    int N;
    cin >> N;
    int a = 0;
    for(int i = 1; i <= N; i++) {
        if(gcd(i, N) == 1) {
            a++;
        }
    }
    cout << a << endl;
}