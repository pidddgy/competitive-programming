// https://dmoj.ca/problem/globexcup18j4

#include <bits/stdc++.h>
#define ll long long
ll a, b, c, d, e, N;
int m = 1000000007;
using namespace std;

int f(int x) {
    if(x == 0) return e;
    else return a * f(x / b)%m + c * f(x / d)%m;
}

int main() {
    
    cin >> a >> b >> c >> d  >> e >> N;
    cout << f(N)%m << endl;
}
