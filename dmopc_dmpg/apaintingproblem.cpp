// https://dmoj.ca/problem/dmopc18c5p1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long

using namespace std;

string b(ll N) {
    string r;
    while(N != 1) {
        r = to_string(N % 2) + r;
        N /= 2;
    }
    r = to_string(N % 2) + r;
    N /= 2;
    return r;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    string Ns = b(N);
    string Ms = b(M);

    int maxx = max(Ns.size(), Ms.size());
    ll p = 0;
    ll b = 0;

    while(Ns.size() < maxx) Ns = "0" + Ns;
    while(Ms.size() < maxx) Ms = "0" + Ms;

    for(int i = 1; i <= K; i++) {
        if( ((Ns[Ns.size()-i]-'0') ^ (Ms[Ms.size()-i]-'0')) == 1 ) {
            b++;
        } else
            p++;
    }

    cout << b << " " << p << endl;
}
