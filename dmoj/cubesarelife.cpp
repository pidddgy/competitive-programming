// https://dmoj.ca/problem/rgpc17p2

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;
    unsigned long long psa[N];
    unordered_map<int, int> A;

    for(int i = 0; i < N; i++) {
        int cube; cin >> cube;
        psa[i] = cube;
        if(i > 0) psa[i] += psa[i-1];
        A[cube] = i;
    }
    
    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        a = A[a];
        b = A[b];

        unsigned long long money;
        if(a == 0)
            money = psa[b];
        else
            money = psa[b] - psa[a-1];

        if(money >= M*2)
            cout << "Enough\n";
        else
            cout << "Not enough\n";
    }
}
