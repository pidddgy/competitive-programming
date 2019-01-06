// https://dmoj.ca/problem/nccc5j2

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int A[N];
    int C[100]; for(int i = 0; i < 100; i++) C[i] = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        C[ A[i] ]++;
    }

    int maxNum = *max_element(C, C+100);
    
}