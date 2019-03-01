// https://dmoj.ca/problem/dmpg15b4

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    int A[N];
    int nc = 0;
    int zeroCount = 0;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] < 0) nc++;
        if(A[i] == 0) {
            zeroCount++;
        }
    }
    if(N == 1) {
        cout << A[0] << endl;
        return 0;
    }
    if(nc == 1 && zeroCount == N-1) {
        cout << 0 << endl;
    } else {
        if(nc % 2 == 0) {
            long long total = 0;
            for(int i = 0; i < N; i++) {
                if(total == 0) total = A[i];
                else if(A[i] != 0) total *= A[i];
            }
             
            cout << total << endl;

        } else {
            long long total = 0;
            int gn = -2147483647;
            bool avoided = false;

            for(int i = 0; i < N; i++)
                if(A[i] < 0 && A[i] > gn)
                    gn = A[i];

            for(int i = 0; i < N; i++) {
                if(A[i] == gn && !avoided) avoided = true;
                else if(total == 0) total = A[i]; 
                else if(A[i] != 0) total *= A[i];
            }

            cout << total << endl;
        }
    }
}
