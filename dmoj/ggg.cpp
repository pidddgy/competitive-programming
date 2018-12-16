// https://dmoj.ca/problem/vmss7wc16c2p3

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int prevRow[min(N+1, M+1)];
    int currRow[min(N+1, M+1)];
    
    cin >> N;
    int J[N+1];
    for(int i = 1; i < N+1; i++)
        cin >> J[i];

    cin >> M;
    int L[M+1];
    for(int i = 1; i < M+1; i++)
        cin >> L[i];

    for(int i = 0; i < M+1; i++) {
        currRow[i] = 0;
        prevRow[i] = 0;
    }

    for(int i = 1; i < N+1; i++) {
        for(int j = 1; j < M+1; j++)
            if(J[i] == L[j])
                currRow[j] = prevRow[j-1] + 1;
            else
                currRow[j] = max(currRow[j-1], prevRow[j]);
        copy(currRow, currRow+M+1, prevRow);
    }
    cout << prevRow[M] << "\n";
}
