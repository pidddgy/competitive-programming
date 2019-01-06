// https://dmoj.ca/problem/lkp18c2p2

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    int aqt[N];
    int count[N];
    for(int i = 0; i < N; i++) count[i] = 0;
    for(int i = 0; i < N; i++) {
        cin >> aqt[i];
    }
    
    int prefsum = 0;
    int total = 0;
    for(int elem: aqt) {
        prefsum += elem;
        prefsum %= K;
        count[prefsum]++;
    }

    for(int i = 0; i < K; i++) {
        total += count[i] * count[i-1] / 2;
    }
    cout << total+1 << endl;
}

