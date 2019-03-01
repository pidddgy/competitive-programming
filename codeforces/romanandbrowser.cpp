// http://codeforces.com/contest/1100/problem/0
// PLEASE DONT HACK ME FOR THE SAKE OF MY RATING :((((
    
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int A[n];
    int S = 0;
    int P = 0;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(A[i] == -1) S++;
        else P++;
    }

    int cqt = -2147483647;
    for(int i = 0; i < k; i++) {
        int curS = S;
        int curP = P;
        for(int j = i; j < n; j += k) {
            if(A[j] == 1) curP--; // productivity
            else curS--; // social
        }

        if(abs(curP-curS) > cqt) {
            cqt = abs(curP-curS);
        }
    }
    cout << cqt << endl;
}

