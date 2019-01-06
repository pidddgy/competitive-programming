// https://dmoj.ca/problem/utso18p3

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, T, K, V;
    cin >> N >> T >> K >> V;
    int aqt[N]; for(int i = 0; i < N; i++) aqt[i] = 0;
    for(int i = 0; i < V; i++) {
        int aqtisadorable;
        cin >> aqtisadorable;
        aqt[aqtisadorable-1] = 1;
    }

    deque<int> dqt;
    int sum = 0;
    for(int i = 0; i < T; i++) {
        dqt.emplace_back(aqt[i]);
        sum += aqt[i];
    }

    for(int i = T; i <= N; i++) {

        for(auto aa: dqt) {
            cout << aa << " ";
        }
        sum-= dqt.front();
        dqt.pop_front();
        dqt.emplace_back(aqt[i]);
        cout << endl;
    }
}