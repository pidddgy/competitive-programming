#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int A[1010] = {};
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[a]++;

    }
    int odd = 0;
    for(int i = 1; i <= K; i++) {
        if(A[i]%2) odd++;

    }
    cout << N - odd/2 << endl;
}