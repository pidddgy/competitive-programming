#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a) {
    for(int i = 2; i < a/2; i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;

        N *= 2;

        // Find two primes that add up to N;

        for(int i = 2; i < N; i++) {
            if(isPrime(i) && isPrime(N-i)) {
                cout << i << " " << N-i << "\n";
                break;
            }
        }
    }
}