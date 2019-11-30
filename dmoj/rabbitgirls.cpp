// https://dmoj.ca/problem/halloween14p1

#include <bits/stdc++.h>
#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
using namespace std;
int main() {
    ll N, K;
    cin >> N >> K;

    ll l = K * ((N/K) - 1);
    ll h = K * ((N/K) + 1);

    ll ld = abs(N-l);
    ll hd = abs(N-h);
    
    if(N % K == 0) {
        cout << 0 << endl;
    } else if(ld < hd) {
        cout << ld << endl;
    } else {
        cout << hd << endl;
    }
}
