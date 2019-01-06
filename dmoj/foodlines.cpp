// https://dmoj.ca/problem/lkp18c2p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int aqt[N];
    for(int i = 0; i < N; i++) {
        cin >> aqt[i];
    }
    for(int i = 0; i < M; i++) {
        cout << *min_element(aqt, aqt+N) << endl;
        aqt[distance(aqt, min_element(aqt, aqt+N))]++;
    }

}