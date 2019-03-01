// https://dmoj.ca/problem/utso18p3

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, T, K, V;
    cin >> N >> T >> K >> V;
    int AQT_IS_ADORABLE[N]; for(int i = 0; i < N; i++) AQT_IS_ADORABLE[i] = 0;
    for(int i = 0; i < V; i++) {
        int cute; cin >> cute;
        AQT_IS_ADORABLE[cute-1] = 1;
    }

    deque<int> dqt;
    int sum = 0;
    for(int i = 0; i < T; i++) {
        dqt.emplace_back(i);
        sum += AQT_IS_ADORABLE[i];
    }
    
    int aqqtttttttt = 0;
    for(int i = T; i <= N; i++) {
        if(sum < K)
            for(int i = dqt.size()-1; i >= 0 && sum < K; i--)
                if(AQT_IS_ADORABLE[dqt[i]] == 0) {
                    AQT_IS_ADORABLE[dqt[i]] = 1;
                    sum++;
                    aqqtttttttt  ++;
                }

        sum += AQT_IS_ADORABLE[i];
        sum -= AQT_IS_ADORABLE[i-T];
        dqt.pop_front();
        dqt.emplace_back(i);
    }

    cout << aqqtttttttt << endl;
}
