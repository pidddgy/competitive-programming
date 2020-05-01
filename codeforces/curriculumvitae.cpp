// https://codeforces.com/contest/846/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
 
    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int best = 0;
    for(int i = 0; i <= N; i++) {
        int rem = 0;
        for(int j = 1; j <= i; j++) {
            if(a[j] != 0) rem++;
        }

        for(int j = i+1; j <= N; j++) {
            if(a[j] != 1) rem++;
        }

        best = max(best, N-rem);
    }
    
    cout << best << endl;
}