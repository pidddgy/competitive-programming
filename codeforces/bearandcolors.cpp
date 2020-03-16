// https://codeforces.com/contest/643/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int cnt[N+1];
    for(int i = 1; i <= N; i++) cnt[i] = 0;

    for(int i = 1; i <= N; i++) {
        int subcnt[N+1];
        for(int i = 1; i <= N; i++) subcnt[i] = 0;
        int curBest = a[i];
        cnt[curBest]++;
        subcnt[a[i]]++;

        for(int j = i+1; j <= N; j++) {
            subcnt[a[j]]++;
            if(subcnt[a[j]] > subcnt[curBest]) {
                curBest = a[j];
            } else if(subcnt[a[j]] == subcnt[curBest] and a[j] < curBest) {
                curBest = a[j];
            }

            cnt[curBest]++;
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
}