// https://dmoj.ca/problem/seed3

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int I, N, J;
    cin >> I >> N >> J;

    int dsa[I+1];
    int psa[I+1];

    for(int i = 0; i < I+1; i++) {
        psa[i] = 0;
        dsa[i] = 0;
    }

    for(int i = 0; i < J; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        dsa[a] += k;
        dsa[b+1] -= k;
    }
    
    // Construct prefix array
    for(int i = 1; i < I+1; i++)
        psa[i] = psa[i-1] + dsa[i];

    int ret = 0;
    for(int i = 1; i < I+1; i++)
        if(psa[i] < N)
            ret++;

    cout << ret << "\n";
}
