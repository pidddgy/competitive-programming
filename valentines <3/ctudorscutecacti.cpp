// https://dmoj.ca/problem/valentines19s2

#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    int R[N]; 
    int C[N];
    for(int i = 0; i < N; i++) {
        R[i] = 0;
        C[i] = 0;
    }

    map<pair<int, int>, int> t;

    for(int s = 0; s < Q; s++) {
        int a, i, j;
        cin >> a >> i >> j;
        i -= 1; j -= 1;

        if(a == 1) {
            R[i] += 1;
            C[j] += 1;
            t[mp(i, j)] += 1;
        } else {
            if( ((R[i] + C[j]) - t[mp(i, j)]) % 2 == 0) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }

}
