// http://wcipeg.com/problem/wc183i3

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, K; // M == budget
    cin >> N >> M >> K;

    int maxV = 0;
    deque<int> pmon[K+1];

    for(int i = 1; i < N+1; i++) {
        int t, l;
        cin >> t >> l;
        pmon[t].push_back(l);
    }

    for(int i = 1; i < K+1; i++) {
        sort(pmon[i].begin(), pmon[i].end(), greater<int>());
    }

    for(int i = 1; i < K+1; i++) {
        M--;
        maxV += pmon[i].front();
        pmon[i].pop_front();
    } 

    while(M--) {
        int max = -420;
        int maxp = 0;
        for(int i = 1; i < K+1; i++) {
            if(pmon[i].front() > max) {
                max = pmon[i].front();
                maxp = i;
            }
        } 

        maxV += max;
        pmon[maxp].pop_front();
    }
    cout << maxV <<  endl;
}
